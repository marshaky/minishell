/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marshaky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 14:57:23 by marshaky          #+#    #+#             */
/*   Updated: 2025/12/28 14:57:24 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*src_holder;
	unsigned char	*dst_holder;

	src_holder = (unsigned char *) src;
	dst_holder = (unsigned char *) dst;
	if (dst_holder > src_holder)
	{
		while (len-- > 0)
		{
			dst_holder[len] = src_holder[len];
		}
	}
	else
		return (ft_memcpy(dst, src, len));
	return (dst_holder);
}
