/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marshaky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 14:58:05 by marshaky          #+#    #+#             */
/*   Updated: 2025/12/28 14:58:06 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			count;

	count = 0;
	while (count < n)
	{
		if (s1[count] == s2[count]
			&& s1[count] && s2[count])
			count++;
		else
		{
			return ((unsigned char)s1[count] - (unsigned char)s2[count]);
		}
	}
	return (0);
}
