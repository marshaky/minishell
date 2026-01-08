/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaghdal <mnaghdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 15:00:47 by marshaky          #+#    #+#             */
/*   Updated: 2025/12/28 15:15:33 by mnaghdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/parsing.h"

char	*clean_quotes(char *cmd)
{
	int		i;
	int		dquotes;
	int		squotes;
	char	*result;

	if (!cmd)
		return (NULL);
	i = 0;
	dquotes = 0;
	squotes = 0;
	result = ft_calloc(ft_strlen(cmd) + 1, sizeof(char));
	while (cmd[0])
	{
		if ((cmd[0] == '"' && (!(squotes & 1) || (dquotes & 1)))
			|| (cmd[0] == '\'' && (!(dquotes & 1) || (squotes & 1))))
		{
			squotes += cmd[0] == '\'';
			dquotes += cmd[0] == '"';
		}
		else
			result[i++] = cmd[0];
		cmd++;
	}
	return (result);
}

void	parsing(t_cmd *cmd)
{
	char	*temp;

	if (!cmd)
		return ;
	temp = replace_variables(cmd->cmd, cmd->prev_error);
	cmd->args = parse_args(temp);
	free(temp);
	if (is_builtin(cmd->args[0]))
		cmd->exec = ft_strdup(cmd->args[0]);
	else
		cmd->exec = parse_exec(cmd->args[0], &cmd->error);
}
