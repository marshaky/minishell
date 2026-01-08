/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaghdal <mnaghdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 13:44:01 by mnaghdal          #+#    #+#             */
/*   Updated: 2025/12/28 15:59:23 by mnaghdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/executions.h"

static int	is_n_flag(char *str)
{
	int	i;

	if (!str || str[0] != '-' || !str[1])
		return (0);
	i = 1;
	while (str[i])
	{
		if (str[i] != 'n')
			return (0);
		i++;
	}
	return (1);
}

static int	check_n_flag(char **args)
{
	int	i;

	if (!args || !args[1])
		return (0);
	i = 1;
	while (args[i] && is_n_flag(args[i]))
		i++;
	return (i - 1);
}

void	echo(t_cmd *cmd)
{
	int	i;
	int	n_flag;

	if (!cmd || !cmd->args)
		return ;
	n_flag = check_n_flag(cmd->args);
	i = n_flag + 1;
	while (cmd->args[i])
	{
		write(STDOUT_FILENO, cmd->args[i], ft_strlen(cmd->args[i]));
		if (cmd->args[i + 1])
			write(STDOUT_FILENO, " ", 1);
		i++;
	}
	if (n_flag == 0)
		write(STDOUT_FILENO, "\n", 1);
	cmd->error = 0;
}
