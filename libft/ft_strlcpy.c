/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marshaky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 14:57:57 by marshaky          #+#    #+#             */
/*   Updated: 2025/12/28 14:57:58 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	src_length;
	size_t	count;

	src_length = ft_strlen(src);
	if (dstsize && !src_length)
		return (0);
	if (!dstsize)
		return (src_length);
	count = 0;
	while (count < (dstsize - 1) && src[count])
	{
		dst[count] = src[count];
		count++;
	}
	dst[count] = '\0';
	return (src_length);
}
