/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marshaky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 14:57:55 by marshaky          #+#    #+#             */
/*   Updated: 2025/12/28 14:57:56 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	src_length;
	size_t	dst_length;
	size_t	count;

	if ((!dst && !src) && !dstsize)
		return (0);
	if (!dstsize)
		return (ft_strlen(src));
	src_length = ft_strlen(src);
	dst_length = ft_strlen(dst);
	count = 0;
	if (dstsize <= dst_length)
		return (src_length + dstsize);
	while (src[count] && count < dstsize - dst_length -1)
	{
		dst[dst_length + count] = src[count];
		count++;
	}
	dst[dst_length + count] = '\0';
	return (src_length + dst_length);
}
