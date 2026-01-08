/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marshaky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 14:57:46 by marshaky          #+#    #+#             */
/*   Updated: 2025/12/28 14:57:47 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	count;

	count = 0;
	while (count <= ft_strlen(s))
	{
		if (s[count++] == (char)c)
		{
			return ((char *)s + --count);
		}
	}
	return (NULL);
}
