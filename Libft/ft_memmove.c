/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 19:35:00 by marshaky          #+#    #+#             */
/*   Updated: 2025/12/07 19:35:01 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const char	*copy_src;
	char		*copy_dst;

	copy_dst = (char *) dst;
	copy_src = (const char *) src;
	if (!dst && !src)
		return (NULL);
	if (dst > src && dst < src + len)
	{
		while (len != 0)
		{
			copy_dst[len -1] = copy_src[len -1];
			len --;
		}
	}
	else
		ft_memcpy(copy_dst, copy_src, len);
	return (dst);
}
/*
#include <stdio.h>
#include <string.h>

int main()
{
    char str1[] = "Keks";
	char str2[] = "qiyeg";

    puts("str1 before memmove ");
    puts(str1);

    ft_memmove(str1, str1+2, 2);

    puts("\nstr1 after memmove ");
    puts(str1);

    return 0;
}*/
