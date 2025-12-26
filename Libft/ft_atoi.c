/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 19:33:09 by marshaky          #+#    #+#             */
/*   Updated: 2025/12/07 19:33:12 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	long	n;

	n = 0;
	i = 0;
	sign = 1;
	while (str[i] != '\0' && ((str[i] >= 9 && str[i] <= 13) || str[i] == ' '))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = (10 * n) + (str[i] - '0');
		if ((sign == 1 && n > INT_MAX) || (sign == -1 && (-n) < INT_MIN))
			return (0);
		i++;
	}
	return ((int)(sign * n));
}

// #include <stdio.h>
// int main()
// {
// 	char c[] = " +-1234567";
// 	int k = ft_atoi(c);
// 	printf ("%d", k);
// }
