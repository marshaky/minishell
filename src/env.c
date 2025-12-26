/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 19:32:30 by marshaky          #+#    #+#             */
/*   Updated: 2025/12/25 23:10:37 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	dp_count(char **dp)
{
	int	i;

	i = 0;
	while (dp && dp[i])
		i++;
	return (i);
}

char	**copy_env(char **envp)
{
	char	**copy;
	int		i;

	copy = malloc(sizeof(char *) * (dp_count(envp) + 1));
	if (!copy)
		exit((print_error("malloc failed in copy_env"), EXIT_FAILURE));
	i = 0;
	while (envp[i])
	{
		copy[i] = ft_strdup(envp[i]);
		if (!copy[i])
		{
			while (--i >= 0)
				free(copy[i]);
			free(copy);
			print_error("ft_strdup failed in copy_env");
			exit(EXIT_FAILURE);
		}
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

char	*get_env_value(const char *name, char **envp)
{
	int	i;
	int	len;

	if (!envp || !name)
		return (NULL);
	len = ft_strlen(name);
	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], name, len) == 0 && envp[i][len] == '=')
			return (envp[i] + len + 1);
		i++;
	}
	return (NULL);
}

int	find_env_var(const char *name, char **envp)
{
	int	i;
	int	len;

	if (!envp || !name)
		return (-1);
	len = ft_strlen(name);
	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], name, len) == 0 && envp[i][len] == '=')
			return (i);
		i++;
	}
	return (-1);
}

int	add_env_var(const char *var, char ***envp)
{
	int		i;
	int		count;
	char	**new_env;

	count = 0;
	while ((*envp)[count])
		count++;
	new_env = malloc(sizeof(char *) * (count + 2));
	if (!new_env)
		return (1);
	i = -1;
	while ((*envp)[++i])
	{
		new_env[i] = (*envp)[i];
	}
	new_env[i] = ft_strdup(var);
	if (!new_env[i])
	{
		free(new_env);
		return (1);
	}
	new_env[i + 1] = NULL;
	free(*envp);
	*envp = new_env;
	return (0);
}
