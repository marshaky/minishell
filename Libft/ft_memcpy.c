/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 19:34:55 by marshaky          #+#    #+#             */
/*   Updated: 2025/12/07 19:34:57 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*copy_dst;
	const char	*copy_src;

	copy_dst = (char *) dst;
	copy_src = (const char *) src;
	i = 0;
	if (!dst && !src)
		return (NULL);
	while (i < n)
	{
		copy_dst[i] = copy_src[i];
		i++;
	}
	return (dst);
}
/*
#include <stdio.h>
int main()
{
    char str1[] = "Iness";
    char str2[] = "Qu";

    ft_memcpy(str1, str2, 4);
	printf("%s\n",str1);
    return 0;
}*/
