/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 23:10:55 by marshaky          #+#    #+#             */
/*   Updated: 2025/12/25 23:10:57 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	valid_var(const char *name)
{
	int	i;

	if (!name || !name[0])
		return (0);
	if (!ft_isalpha(name[0]) && name[0] != '_')
		return (0);
	i = 1;
	while (name[i])
	{
		if (!ft_isalnum(name[i]) && name[i] != '_')
			return (0);
		i++;
	}
	return (1);
}

int	match_var(const char *env_var, const char *name)
{
	int	i;

	i = 0;
	if (!env_var || !name || !*env_var || !*name)
		return (0);
	while (name[i] && env_var[i] && name[i] == env_var[i])
		i++;
	if (name[i] == '\0' && env_var[i] == '=')
		return (1);
	return (0);
}

// static int	count_env_vars(const char *name, char **envp)
// {
// 	int	count;
// 	int	i;

// 	count = 0;
// 	i = 0;
// 	while (envp[i])
// 	{
// 		if (!match_var(envp[i], name))
// 			count++;
// 		i++;
// 	}
// 	return (count);
// }

static void	unset_env_var(const char *name, char ***envp)
{
	int		i;
	int		j;
	int		count;
	char	**new_env;
	char	**cur;

	cur = *envp;
	count = dp_count(cur);
	new_env = malloc(sizeof(char *) * (count + 1));
	if (!new_env)
		return ;
	i = 0;
	j = 0;
	while (cur[i])
	{
		if (!match_var(cur[i], name))
			new_env[j++] = cur[i];
		else
			free(cur[i]);
		i++;
	}
	new_env[j] = NULL;
	free(cur);
	*envp = new_env;
}

void	ft_unset(char **tokens, char ***envp)
{
	int	i;
	int	error;

	i = 1;
	error = 0;
	while (tokens[i])
	{
		if (!valid_var(tokens[i]))
		{
			ft_putstr_fd("\e[0;31munset: '", 2);
			ft_putstr_fd(tokens[i], 2);
			ft_putstr_fd("': not a valid identifier\e[0m\n", 2);
			error = 1;
		}
		else
			unset_env_var(tokens[i], envp);
		i++;
	}
	if (error)
		g_signal = 1;
}
