/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 19:36:34 by marshaky          #+#    #+#             */
/*   Updated: 2025/12/07 19:36:35 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*subs;
	size_t	lenght;

	lenght = ft_strlen(s);
	i = 0;
	if (!s)
		return (NULL);
	if (start >= lenght)
		return (ft_strdup(""));
	if (len > lenght - start)
		len = lenght - start;
	subs = (char *)malloc(len * sizeof(char) + 1);
	if (!subs)
		return (NULL);
	while (i < len)
	{
		subs[i] = s[start + i];
		i++;
	}
	subs[i] = '\0';
	return (subs);
}
