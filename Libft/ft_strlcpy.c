/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 19:36:02 by marshaky          #+#    #+#             */
/*   Updated: 2025/12/25 23:18:09 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	m;

	i = ft_strlen(src);
	m = 0;
	if (dstsize == 0)
		return (i);
	if (dstsize != 0)
	{
		while (m < dstsize -1 && src[m] != '\0')
		{
			dst[m] = src[m];
			m++;
		}
	}
	dst[m] = '\0';
	return (i);
}
/*
#include <stdio.h>
#include <string.h>

void test(int size)
{
    char string[] = "Hello there, Venus";
    char buffer[19];
    int r;

    r = ft_strlcpy(buffer,string,size);

    printf("Copied '%s' into '%s', length %d\n",
            string,
            buffer,
            r
          );
}

int main()
{
    test(19);
    test(10);
    test(1);
    test(0);

    return(0);
}*/
