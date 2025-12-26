/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 19:35:05 by marshaky          #+#    #+#             */
/*   Updated: 2025/12/07 19:35:07 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*copy_b;
	size_t			i;

	copy_b = b;
	i = 0;
	while (i < len)
	{
		copy_b[i] = c;
		i++;
	}
	return (b);
}
/*
#include <stdio.h>
int main()
{
	char str[] = "123456";
	char str1[] = "123456";
	memset (str, 93, 5);
	ft_memset (str1, 93, 5);
	printf("%s\n%s", str, str1);
}
*/
