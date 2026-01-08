/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marshaky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 14:57:20 by marshaky          #+#    #+#             */
/*   Updated: 2025/12/28 14:57:21 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*src_holder;
	unsigned char	*dst_holder;
	size_t			counter;

	src_holder = (unsigned char *) src;
	dst_holder = (unsigned char *) dst;
	if (!dst_holder || (!src_holder && !dst_holder))
		return (NULL);
	if (!src_holder)
		return (dst_holder);
	counter = 0;
	while (counter < n)
	{
		*(unsigned char *)(dst + counter) = src_holder[counter];
		counter++;
	}
	return (dst_holder);
}
