/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 19:34:49 by marshaky          #+#    #+#             */
/*   Updated: 2025/12/07 19:34:51 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*copy_s1;
	const unsigned char	*copy_s2;

	i = 0;
	copy_s1 = s1;
	copy_s2 = s2;
	while (i < n)
	{
		if (copy_s1[i] != copy_s2[i])
			return (copy_s1[i] - copy_s2[i]);
		i++;
	}
	return (0);
}
