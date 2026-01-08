/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marshaky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 14:57:50 by marshaky          #+#    #+#             */
/*   Updated: 2025/12/28 14:57:51 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	count;
	unsigned int	length;

	if (s && f)
	{
		count = 0;
		length = ft_strlen(s);
		while (count < length)
		{
			f(count, &s[count]);
			count++;
		}
	}
}
