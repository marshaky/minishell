/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marshaky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 14:57:17 by marshaky          #+#    #+#             */
/*   Updated: 2025/12/28 14:57:18 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			counter;
	unsigned char	*txt1;
	unsigned char	*txt2;

	txt1 = (unsigned char *)s1;
	txt2 = (unsigned char *)s2;
	counter = 0;
	while (counter < n)
	{
		if (txt1[counter] == txt2[counter])
		{
			counter++;
		}
		else
		{
			return (txt1[counter] - txt2[counter]);
		}
	}
	return (0);
}
