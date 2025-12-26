/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 19:32:30 by marshaky          #+#    #+#             */
/*   Updated: 2025/12/25 23:23:09 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_pwd(void)
{
	char	*cwd;

	cwd = getcwd(NULL, 0);
	if (!cwd)
	{
		print_error("pwd: getcwd error");
		return ;
	}
	write(1, cwd, ft_strlen(cwd));
	write(1, "\n", 1);
	free(cwd);
}

void	print_export(char **envp)
{
	char	*equal_sign;
	int		i;

	i = 0;
	while (envp[i])
	{
		ft_putstr_fd("declare -x ", 1);
		equal_sign = ft_strchr(envp[i], '=');
		if (equal_sign)
		{
			write(1, envp[i], equal_sign - envp[i]);
			ft_putstr_fd("=\"", 1);
			ft_putstr_fd(equal_sign + 1, 1);
			ft_putstr_fd("\"\n", 1);
		}
		else
		{
			ft_putstr_fd(envp[i], 1);
			ft_putstr_fd("\n", 1);
		}
		i++;
	}
}

int	ft_export(char **tokens, char ***envp)
{
	int		idx;
	char	*equal_sign;
	char	*var_name;

	if (!tokens[1])
		return (print_export(*envp), 0);
	while (*++tokens)
	{
		((equal_sign = ft_strchr(*tokens, '=')) && 0) || ((equal_sign && \
				(var_name = ft_substr(*tokens, 0, equal_sign - *tokens)))
				|| (!equal_sign && (var_name = ft_strdup(*tokens), 1)));
		if (!var_name || !valid_var(var_name))
			return (print_error("export error"), free(var_name), 1);
		idx = find_env_var(var_name, *envp);
		if (idx >= 0)
		{
			// (free((*envp)[idx]), 1) && ((*envp)[idx] = ft_strdup(*tokens), 1);
			free((*envp)[idx]);
			(*envp)[idx] = ft_strdup(*tokens);
			if (!(*envp)[idx])
				return (free(var_name), 1);
		}
		else if (equal_sign && add_env_var(*tokens, envp) != 0)
			return (free(var_name), 1);
		free(var_name);
	}
	return (0);
}

int	count_tokens(const char *input, char **envp)
{
	const char	*p;
	int			count;
	char		*token;

	p = input;
	count = 0;
	token = get_token(&p, envp);
	while (token)
	{
		count++;
		free(token);
		token = get_token(&p, envp);
	}
	return (count);
}

char	**tokenize(const char *input, char **envp)
{
	int			i;
	char		**tokens;
	char		*token;
	const char	*p;

	i = count_tokens(input, envp);
	tokens = malloc(sizeof(char *) * (i + 1));
	if (i < 0 || !tokens)
		return (NULL);
	i = 0;
	p = input;
	while (*p)
	{
		token = get_token(&p, envp);
		if (!token)
			return (NULL);
		tokens[i++] = token;
	}
	tokens[i] = NULL;
	return (tokens);
}
