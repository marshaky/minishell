/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_pipes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaghdal <mnaghdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 13:06:59 by mnaghdal          #+#    #+#             */
/*   Updated: 2025/12/28 15:09:51 by mnaghdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/executions.h"
#include "../headers/main.h"

static int	exec_pipes(t_cmd *cmds, int pfd[2], int oldpfd[2], int count)
{
	if (!count)
	{
		execute_cmd(cmds, pfd, (int [2]){0, 1}, NULL);
		close(pfd[1]);
	}
	else if (!cmds->sep || cmds->sep[0] != '|')
	{
		execute_cmd(cmds, oldpfd, (int [2]){1, 0}, NULL);
		close(oldpfd[0]);
		return (1);
	}
	else
	{
		execute_cmd(cmds, oldpfd, (int [2]){1, 1}, pfd);
		close(oldpfd[0]);
		close(pfd[1]);
	}
	oldpfd[0] = pfd[0];
	oldpfd[1] = pfd[1];
	return (0);
}

static pid_t	*allocate_pids_block(t_cmd *cmds)
{
	int	count;

	count = 0;
	while (cmds && cmds->sep && cmds->sep[0] == '|')
	{
		count++;
		cmds = cmds->next;
	}
	return (ft_calloc(count + 2, sizeof(pid_t)));
}

static	void	extract_err_code(t_cmd *cmds, pid_t *pids)
{
	int	count;
	int	status;

	count = 0;
	while (pids[count])
	{
		waitpid(pids[count++], &status, 0);
		cmds->error = WEXITSTATUS(status);
		if (WTERMSIG(status) == SIGINT)
			cmds->error = 130;
	}
	free(pids);
	signal(SIGINT, sig_handler);
}

t_cmd	*run_pipe_commands(t_cmd *cmds, int *err)
{
	int		count;
	int		pfd[2];
	int		oldpfd[2];
	pid_t	*pids;

	count = 0;
	pids = allocate_pids_block(cmds);
	while (cmds)
	{
		pipe(pfd);
		if (exec_pipes(cmds, pfd, oldpfd, count))
		{
			pids[count] = cmds->process_id;
			break ;
		}
		pids[count++] = cmds->process_id;
		cmds = get_next_cmd(cmds, err);
	}
	close(pfd[0]);
	close(pfd[1]);
	extract_err_code(cmds, pids);
	return (cmds);
}
