/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marshaky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 14:57:14 by marshaky          #+#    #+#             */
/*   Updated: 2025/12/28 14:57:15 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	count;
	char	*holder;

	count = 0;
	holder = (char *)s;
	while (count < n)
	{
		if (holder[count++] == (char)c)
		{
			return ((char *)s + --count);
		}
	}
	return (NULL);
}
