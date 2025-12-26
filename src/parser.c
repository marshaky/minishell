/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 23:10:47 by marshaky          #+#    #+#             */
/*   Updated: 2025/12/25 23:10:49 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	append_val(char *buf, int *bufpos, char *val, int do_free)
{
	int	len;

	if (!val)
		return (0);
	len = ft_strlen(val);
	ft_memcpy(buf + *bufpos, val, len);
	*bufpos += len;
	if (do_free)
		free(val);
	return (0);
}

static char	*parse_operator(const char **p)
{
	char	op[3];

	if (**p == '>' && *((*p) + 1) == '>')
	{
		*p += 2;
		return (ft_strdup(">>"));
	}
	else if (**p == '<' && *((*p) + 1) == '<')
	{
		*p += 2;
		return (ft_strdup("<<"));
	}
	op[0] = **p;
	op[1] = '\0';
	(*p)++;
	return (ft_strdup(op));
}

static int	parse_var(const char **p, char *buf, int *bufpos, char **envp)
{
	const char	*start;
	const char	*s;
	char		*name;

	start = *p + 1;
	if (*start == '?')
	{
		append_val(buf, bufpos, ft_itoa(g_signal), 1);
		*p += 2;
		return (1);
	}
	if (!(*start == '_') && !ft_isalpha(*start))
		return (0);
	s = start + 1;
	while (*s == '_' || ft_isalnum(*s))
		s++;
	name = ft_substr(start, 0, s - start);
	if (name)
	{
		append_val(buf, bufpos, get_env_value(name, envp), 0);
		free(name);
	}
	*p = s;
	return (1);
}

static char	*join_token_parts(const char **p, char **envp)
{
	char	buffer[1024];
	int		bufpos;
	char	cur;

	bufpos = 0;
	while (**p && !ft_isspace(**p) && !is_operator(**p))
	{
		if ((**p == '\'' || **p == '"') && ft_strchr(*p + 1, **p))
		{
			cur = *(*p)++;
			while (**p && **p != cur)
				if (!(cur == '"' && **p == '$' && parse_var(p, buffer, &bufpos,
							envp)))
					buffer[bufpos++] = *(*p)++;
			(void)((**p == cur) && (*p)++);
		}
		else
		{
			if (**p == '$' && parse_var(p, buffer, &bufpos, envp))
				continue ;
			buffer[bufpos++] = *(*p)++;
		}
	}
	return (buffer[bufpos] = '\0', ft_strdup(buffer));
}

char	*get_token(const char **p, char **envp)
{
	while (*p && ft_isspace(**p))
		(*p)++;
	if (!**p)
		return (NULL);
	if (is_operator(**p))
		return (parse_operator(p));
	return (join_token_parts(p, envp));
}
