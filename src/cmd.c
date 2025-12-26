/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 23:10:20 by marshaky          #+#    #+#             */
/*   Updated: 2025/12/26 15:48:27 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#define MAX_REDIR 32

static void try_exec(char **tokens, char **envp)
{
    char    *cmd;
    char    **paths;
    char    *path_var;
    int     i;
    char    *dir;
    char    *full;
    size_t  d;
    size_t  c;

    cmd = tokens[0];
    path_var = get_env_value("PATH", envp);
    if (!path_var || !*path_var)
    {
        ft_putstr_fd(cmd, 2);
        ft_putstr_fd(": command not found\n", 2);
        exit(127);
    }
    paths = ft_split(path_var, ':');
    i = 0;
    while (paths && paths[i])
    {
        dir = paths[i][0] ? paths[i] : ".";
        d = ft_strlen(dir);
        c = ft_strlen(cmd);
        full = malloc(d + c + 2);
        if (!full)
            break ;
        ft_memcpy(full, dir, d);
        full[d] = '/';
        ft_memcpy(full + d + 1, cmd, c + 1);
        execve(full, tokens, envp);
        free(full);
        i++;
    }
    free_dp(paths);
    ft_putstr_fd(cmd, 2);
    ft_putstr_fd(": command not found\n", 2);
    exit(127);
}



int	exec(char **tokens, char **envp)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid < 0)
		return (perror("fork"), 0);
	if (pid == 0)
	{
		struct stat st;
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);

		if (ft_strchr(tokens[0], '/'))
		{
			if (stat(tokens[0], &st) == 0 && S_ISDIR(st.st_mode))
			{
				ft_putstr_fd(tokens[0], 2);
				ft_putstr_fd(": is a directory\n", 2);
				exit(126);
			}
			execve(tokens[0], tokens, envp);
			perror(tokens[0]);
			exit(errno == EACCES ? 126 : 127);
		}
		try_exec(tokens, envp);
	}
	waitpid(pid, &status, 0);
	((WIFEXITED(status) && ((g_signal = WEXITSTATUS(status)), 1))
		|| (g_signal = 1));
	return (g_signal != 127);
}

static int	is_builtin(char **tokens)
{
	if (!tokens || !tokens[0])
		return (0);
	if (!ft_strncmp(tokens[0], "echo", ft_strlen("echo")))
		return (1);
	if (!ft_strncmp(tokens[0], "cd", ft_strlen("cd")))
		return (1);
	if (!ft_strncmp(tokens[0], "pwd", ft_strlen("pwd")))
		return (1);
	if (!ft_strncmp(tokens[0], "export", ft_strlen("export")))
		return (1);
	if (!ft_strncmp(tokens[0], "unset", ft_strlen("unset")))
		return (1);
	if (!ft_strncmp(tokens[0], "env", ft_strlen("env")))
		return (1);
	if (!ft_strncmp(tokens[0], "exit", ft_strlen("exit")))
		return (1);
	return (0);
}

int	inner_cmd(char **tokens, char ***envp)
{
	return (tokens && tokens[0] && ((!ft_strncmp(tokens[0], "echo", 4)
				&& (ft_echo(tokens), 1)) || (!ft_strncmp(tokens[0], "cd", 2)
				&& ((g_signal = ft_cd(tokens, *envp)), 1))
			|| (!ft_strncmp(tokens[0], "pwd", 3) && (ft_pwd(), 1))
			|| (!ft_strncmp(tokens[0], "export", 6)
				&& ((g_signal = ft_export(tokens, envp)), 1))
			|| (!ft_strncmp(tokens[0], "unset", 5) && (ft_unset(tokens, envp),
					1)) || (!ft_strncmp(tokens[0], "env", 3) && (ft_env(*envp),
					1)) || (!ft_strncmp(tokens[0], "exit", 4)
				&& (ft_exit(tokens), 1)) || exec(tokens, *envp)));
}

typedef struct s_cmd
{
	char	**argv;
	char	*infile;
	char	*outfile;
	char	*heredoc;
	int		append;
}			t_cmd;

static int	setup_infile(t_cmd *cmd, int *fdin)
{
	int		pipefd[2];
	char	*line;

	if (cmd->heredoc)
	{
		if (pipe(pipefd) == -1)
			return (perror("pipe"), -1);
		while (1)
		{
			line = readline("> ");
			if (!line || (!ft_strncmp(line, cmd->heredoc, ft_strlen(cmd->heredoc) + 1)))
			{
				free(line);
				break ;
			}
			write(pipefd[1], line, ft_strlen(line));
			write(pipefd[1], "\n", 1);
			free(line);
		}
		close(pipefd[1]);
		*fdin = pipefd[0];
		return (0);
	}
	if (cmd->infile)
	{
		*fdin = open(cmd->infile, O_RDONLY);
		if (*fdin < 0)
			return (perror(cmd->infile), -1);
	}
	return (0);
}

static int	setup_outfile(t_cmd *cmd, int *fdout)
{
	int	flags;

	if (cmd->outfile)
	{
		flags = O_WRONLY | O_CREAT;
		if (cmd->append)
			flags |= O_APPEND;
		else
			flags |= O_TRUNC;
		*fdout = open(cmd->outfile, flags, 0644);
		if (*fdout < 0)
			return (perror(cmd->outfile), -1);
	}
	return (0);
}

static void	free_cmds(t_cmd *cmds, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(cmds[i].argv);
		i++;
	}
	free(cmds);
}

static int	run_single_builtin(t_cmd *cmd, char ***envp)
{
	int	saved_in;
	int	saved_out;
	int	fdin;
	int	fdout;

	fdin = -1;
	fdout = -1;
	saved_in = dup(STDIN_FILENO);
	saved_out = dup(STDOUT_FILENO);
	if (setup_infile(cmd, &fdin) < 0)
		return (dup2(saved_in, STDIN_FILENO), dup2(saved_out, STDOUT_FILENO),
			close(saved_in), close(saved_out), g_signal = 1, 1);
	if (fdin >= 0)
		dup2(fdin, STDIN_FILENO);
	if (setup_outfile(cmd, &fdout) < 0)
		return (dup2(saved_in, STDIN_FILENO), dup2(saved_out, STDOUT_FILENO),
			close(saved_in), close(saved_out), g_signal = 1, 1);
	if (fdout >= 0)
		dup2(fdout, STDOUT_FILENO);
	inner_cmd(cmd->argv, envp);
	if (fdin >= 0)
		close(fdin);
	if (fdout >= 0)
		close(fdout);
	dup2(saved_in, STDIN_FILENO);
	dup2(saved_out, STDOUT_FILENO);
	close(saved_in);
	close(saved_out);
	return (0);
}

static void	run_child(t_cmd *cmd, char **envp, int prev_fd, int pipefd[2],
		int is_last, char ***envpp)
{
	int	fdin;
	int	fdout;

	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);

	fdin = -1;
	fdout = -1;
	if (prev_fd != -1)
	{
		dup2(prev_fd, STDIN_FILENO);
		close(prev_fd);
	}
	if (!is_last)
	{
		dup2(pipefd[1], STDOUT_FILENO);
		close(pipefd[0]);
		close(pipefd[1]);
	}
	if (setup_infile(cmd, &fdin) < 0)
		exit(1);
	if (fdin >= 0)
		dup2(fdin, STDIN_FILENO);
	if (setup_outfile(cmd, &fdout) < 0)
		exit(1);
	if (fdout >= 0)
		dup2(fdout, STDOUT_FILENO);
	if (fdin >= 0)
		close(fdin);
	if (fdout >= 0)
		close(fdout);
	if (is_builtin(cmd->argv))
		inner_cmd(cmd->argv, envpp);
	// else
	// 	exec(cmd->argv, envp);
	else
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
		if (ft_strchr(cmd->argv[0], '/'))
		{
			execve(cmd->argv[0], cmd->argv, envp);
			perror(cmd->argv[0]);
			exit(errno == EACCES ? 126 : 127);
		}
		try_exec(cmd->argv, envp);
	}
	exit(g_signal);
}

static int wait_all(pid_t *pids, int n)
{
    int status;
    int i;

    waitpid(pids[n - 1], &status, 0);
    if (WIFEXITED(status))
        g_signal = WEXITSTATUS(status);
    else if (WIFSIGNALED(status))
        g_signal = 128 + WTERMSIG(status);

    i = 0;
    while (i < n - 1)
    {
        waitpid(pids[i], NULL, 0);
        i++;
    }

    return (0);
}

static int	build_commands(char **tokens, t_cmd **out_cmds, int *out_count)
{
	int		count;
	int		i;
	int		argi;
	t_cmd	*cmds;
	int		total;
	int		cmdi;

	count = 1;
	i = 0;
	while (tokens[i])
		if (!ft_strncmp(tokens[i++], "|", 2))
			count++;
	cmds = calloc(count, sizeof(t_cmd));
	if (!cmds)
		return (-1);
	total = 0;
	while (tokens[total])
		total++;
	i = 0;
	cmdi = 0;
	argi = 0;
	cmds[cmdi].argv = calloc(total + 1, sizeof(char *));
	while (tokens[i])
	{
		if (!ft_strncmp(tokens[i], "|", 2))
		{
			cmds[cmdi].argv[argi] = NULL;
			cmdi++;
			argi = 0;
			cmds[cmdi].argv = calloc(total + 1, sizeof(char *));
			i++;
			continue ;
		}
		if (!ft_strncmp(tokens[i], "<", 2) && tokens[i + 1])
			cmds[cmdi].infile = tokens[++i];
		else if (!ft_strncmp(tokens[i], ">", 2) && tokens[i + 1])
		{
			if (cmds[cmdi].outfile)
			{
				int	tmp;
				
				tmp = open(cmds[cmdi].outfile,
						O_WRONLY | O_CREAT | (cmds[cmdi].append ? O_APPEND : O_TRUNC),
						0644);
				if (tmp < 0)
				return (perror(cmds[cmdi].outfile), -1);
				close(tmp);
			}
			cmds[cmdi].outfile = tokens[++i];
			cmds[cmdi].append = 0;
		}

		else if (!ft_strncmp(tokens[i], ">>", 3) && tokens[i + 1])
		{
			if (cmds[cmdi].outfile)
			{
				int tmp;
			
				tmp = open(cmds[cmdi].outfile,
					O_WRONLY | O_CREAT | (cmds[cmdi].append ? O_APPEND : O_TRUNC),
					0644);
				if (tmp < 0)
					return (perror(cmds[cmdi].outfile), -1);
			close(tmp);
			}
			cmds[cmdi].outfile = tokens[++i];
			cmds[cmdi].append = 1;
		}
		else if (!ft_strncmp(tokens[i], "<<", 3) && tokens[i + 1])
			cmds[cmdi].heredoc = tokens[++i];
		else if (tokens[i][0] != '\0')
			cmds[cmdi].argv[argi++] = tokens[i];
		i++;
	}
	cmds[cmdi].argv[argi] = NULL;
	*out_cmds = cmds;
	*out_count = count;
	return (0);
}

int	execute_line(char **tokens, char ***envp)
{
	t_cmd	*cmds;
	int		cmd_count;
	int		i;
	int		prev_fd;
	int		pipefd[2];
	pid_t	*pids;

	if (!tokens || !tokens[0] || !tokens[0][0])
		return (g_signal = 0);

	if (build_commands(tokens, &cmds, &cmd_count) < 0)
		return (g_signal = 1);
	if (cmd_count == 1
		&& cmds[0].heredoc
		&& (!cmds[0].argv || !cmds[0].argv[0]))
	{
		cmds[0].argv = malloc(sizeof(char *) * 2);
		cmds[0].argv[0] = ft_strdup("cat");
		cmds[0].argv[1] = NULL;
	}
	if (cmd_count == 1 && is_builtin(cmds[0].argv))
	{
		run_single_builtin(&cmds[0], envp);
		free_cmds(cmds, cmd_count);
		return (g_signal);
	}
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	pids = malloc(sizeof(pid_t) * cmd_count);
	prev_fd = -1;

	i = 0;
	while (i < cmd_count)
	{
		if (i != cmd_count - 1 && pipe(pipefd) == -1)
			return (perror("pipe"), free_cmds(cmds, cmd_count), free(pids),
				g_signal = 1);
		pids[i] = fork();
		if (pids[i] == 0)
		{
			signal(SIGINT, SIG_DFL);
			signal(SIGQUIT, SIG_DFL);
			// tcsetpgrp(STDIN_FILENO, getpid());
			run_child(&cmds[i], *envp, prev_fd, pipefd, i == cmd_count - 1,
				envp);
			exit(g_signal);
		}
		else
			tcsetpgrp(STDIN_FILENO, pids[i]);
		if (prev_fd != -1)
			close(prev_fd);
		if (i != cmd_count - 1)
			close(pipefd[1]);
		if (i != cmd_count - 1)
			prev_fd = pipefd[0];
		i++;
	}
	if (prev_fd != -1)
		close(prev_fd);
	wait_all(pids, cmd_count);
	tcsetpgrp(STDIN_FILENO, getpgrp());
	free(pids);
	free_cmds(cmds, cmd_count);
	if (g_signal == 130 || g_signal == 131)
	{
		write(1, "\n", 1);
		g_signal = 0;
	}
	signal(SIGINT, sigint_handler);
	signal(SIGQUIT, SIG_IGN);
	return (g_signal);
}

void	remove_empty_tokens(char ***tokens)
{
    char    **old;
    char    **new;
    int     i;
    int     j;
    int     count;

    if (!tokens || !*tokens)
        return ;

    old = *tokens;

    count = 0;
    i = 0;
    while (old[i])
    {
        if (old[i][0] != '\0')
            count++;
        i++;
    }

    new = malloc(sizeof(char *) * (count + 1));
    if (!new)
        return ;

    i = 0;
    j = 0;
    while (old[i])
    {
        if (old[i][0] != '\0')
            new[j++] = old[i];
        else
            free(old[i]);
        i++;
    }
    new[j] = NULL;

    free(old);
    *tokens = new;
}

