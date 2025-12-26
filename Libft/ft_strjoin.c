/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 19:35:50 by marshaky          #+#    #+#             */
/*   Updated: 2025/12/07 19:35:52 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size;
	size_t	m;
	size_t	i;
	char	*array;

	if (!s1 && !s2)
		return (NULL);
	i = 0;
	m = ft_strlen(s1);
	size = ft_strlen(s1) + ft_strlen(s2);
	array = (char *)malloc(size * sizeof(char) + 1);
	if (!array)
		return (NULL);
	while (i < m)
	{
		array[i] = s1[i];
		i++;
	}
	m = 0;
	while (i < size)
		array[i++] = s2[m++];
	array[i] = '\0';
	return (array);
}
