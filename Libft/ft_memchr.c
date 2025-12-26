/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 19:34:45 by marshaky          #+#    #+#             */
/*   Updated: 2025/12/07 19:34:47 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*copy_s;
	unsigned char		copy_c;

	copy_c = (unsigned char)c;
	copy_s = s;
	i = 0;
	while (i < n)
	{
		if (copy_s[i] == copy_c)
			return ((void *)&copy_s[i]);
		i++;
	}
	return (NULL);
}
