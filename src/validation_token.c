/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_token.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 23:11:08 by marshaky          #+#    #+#             */
/*   Updated: 2025/12/25 23:21:09 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_operator(const char *token)
{
	return (ft_strncmp(token, "<", 2) == 0 || ft_strncmp(token, ">", 2) == 0
		|| ft_strncmp(token, ">>", 3) == 0 || ft_strncmp(token, "<<", 3) == 0
		|| ft_strncmp(token, "|", 2) == 0);
}

int	ft_redirection(const char *token)
{
	return (ft_strncmp(token, "<", 2) == 0 || ft_strncmp(token, ">", 2) == 0
		|| ft_strncmp(token, ">>", 3) == 0 || ft_strncmp(token, "<<", 3) == 0);
}

int	validate_tokens(char **tokens)
{
	int	i;

	if (!tokens || !tokens[0])
		return (0);
	if (ft_strncmp(tokens[0], "|", 2) == 0)
		return (0);
	i = 0;
	while (tokens[i])
	{
		if (ft_redirection(tokens[i]))
		{
			if (!tokens[i + 1] || ft_operator(tokens[i + 1]))
				return (0);
		}
		else if (ft_strncmp(tokens[i], "|", 2) == 0)
		{
			if (!tokens[i + 1] || ft_strncmp(tokens[i + 1], "|", 2) == 0)
				return (0);
		}
		i++;
	}
	if (ft_strncmp(tokens[i - 1], "|", 2) == 0)
		return (0);
	return (1);
}
