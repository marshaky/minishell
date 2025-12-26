/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 23:10:27 by marshaky          #+#    #+#             */
/*   Updated: 2025/12/26 03:33:43 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_numeric(const char *str)
{
	int	i;

	i = 0;
	if (str[0] == '+' || str[0] == '-')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	ft_exit(char **args)
{
	int	exit_code;

	write(1, "exit\n", 5);
	if (!args[1])
		exit(g_signal);
	if (!is_numeric(args[1]))
	{
		ft_putstr_fd("exit: numeric argument required\n", 2);
		// g_signal = 2;
		// exit(2);
		exit(255);
	}
	if (args[2])
	{
		ft_putstr_fd("exit: too many arguments\n", 2);
		g_signal = 1;
		return ;
	}
	exit_code = ft_atoi(args[1]);
	exit(exit_code);
}

void	ft_env(char **envp)
{
	int	i;

	i = 0;
	while (envp && envp[i])
	{
		ft_putstr_fd(envp[i], 1);
		ft_putchar_fd('\n', 1);
		i++;
	}
}

void	ft_echo(char **args)
{
	int	i;
	int	newline;

	i = 1;
	newline = 1;
	if (args[1] && !ft_strncmp(args[1], "-n", 3))
	{
		newline = 0;
		i = 2;
	}
	while (args[i])
	{
		ft_putstr_fd(args[i], 1);
		if (args[i + 1])
			write(1, " ", 1);
		i++;
	}
	if (newline)
		write(1, "\n", 1);
}

int	ft_cd(char **args, char **envp)
{
	char	*path;

	if (!args[1])
	{
		path = get_env_value("HOME", envp);
		if (!path)
		{
			ft_putstr_fd("cd: HOME not set\n", 2);
			return (1);
		}
	}
	else
		path = args[1];
	if (chdir(path) != 0)
	{
		ft_putstr_fd("cd: ", 2);
		perror(path);
		return (1);
	}
	return (0);
}
