/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 23:11:03 by marshaky          #+#    #+#             */
/*   Updated: 2025/12/25 23:11:05 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>

int	path_type(const char *path)
{
	struct stat	s;

	if (stat(path, &s) == 0)
	{
		if (S_ISDIR(s.st_mode))
			return (0);
		else if (S_ISREG(s.st_mode))
			return (1);
		else
			return (2);
	}
	else
	{
		perror("stat error");
		return (-1);
	}
}

// 226/358

void	print_error(const char *msg)
{
	write(2, "\e[0;31mminishell: ", 19);
	write(2, msg, ft_strlen(msg));
	write(2, "\e[0m\n", 6);
}

int	is_operator(char c)
{
	return (c == '|' || c == '<' || c == '>');
}

int	ft_isspace(char c)
{
	return (c == 32 || (c >= 9 && c <= 13));
}

void	free_dp(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}
