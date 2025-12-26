/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 19:32:30 by marshaky          #+#    #+#             */
/*   Updated: 2025/12/26 15:53:51 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		g_signal = 0;

char	**update_lvl(char **envp)
{
	int		idx;
	long	val;
	char	*val_str;
	char	*entry;

	if (!envp || !*envp)
		return (0);
	idx = find_env_var("SHLVL", envp);
	val = 0;
	if (idx >= 0)
	{
		val_str = get_env_value("SHLVL", envp);
		// (val_str && *val_str) && (val = ft_atoi(val_str), 1);
		if (val_str && *val_str)
			val = ft_atoi(val_str);
		// (val < 0 || val >= 999) && (val = 0, 1);
		if (val < 0 || val >= 999)
			val = 0;
		val_str = ft_itoa(++val);
		entry = ft_strjoin("SHLVL=", val_str);
		free(val_str);
		free((envp)[idx]);
		(envp)[idx] = entry;
	}
	else
		add_env_var("SHLVL=1", &envp);
	return (envp);
}

void	sigint_handler(int sig)
{
	(void)sig;
	// if (g_signal != 0)
	// 	return;
	write(1, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
	g_signal = 130;
}

void set_signal_prompt(void)
{
	signal(SIGINT, sigint_handler);
	signal(SIGQUIT, SIG_IGN);
}

void set_signal_exec(void)
{
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
}

int	main(int argc, char **argv, char **env)
{
	char	*input;
	char	**tokens;
	char	**envp;

	signal(SIGINT, sigint_handler);
	signal(SIGQUIT, SIG_IGN);	envp = update_lvl(copy_env(env));
	if (!envp)
		return (print_error("failed to create env"), 1);
	while (1)
	{
		set_signal_prompt();
		input = readline("\e[1;35mminishell$\e[0m ");
	// 	if (!input && (ft_putstr_fd("exit\n", 1), 1))
	// 		break ;
	// 	// (*input) && (add_history(input), 1);
		if (!input)
		{
			write(1, "exit\n", 5);
			break;
		}
		if (*input)
			add_history(input);
		tokens = tokenize(input, envp);
	// 	if (!tokens || !validate_tokens(tokens))
	// 		print_error("Syntax error: invalid token sequence");
	// 	else
	// 		execute_line(tokens, &envp);
	    if (tokens && validate_tokens(tokens))
		{
			// set_signal_exec();
			execute_line(tokens, &envp);
		}
		free_dp((free(input), tokens));
	}
	free_dp(envp);
	return (((void)(argc + argv)), g_signal);
}
