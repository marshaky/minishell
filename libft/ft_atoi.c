/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marshaky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 14:55:46 by marshaky          #+#    #+#             */
/*   Updated: 2025/12/28 14:55:47 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	result;
	int	sign;
	int	count;

	result = 0;
	sign = 1;
	count = 0;
	while (str[count] == ' ' || str[count] == '\t' || str[count] == '\v'
		|| str[count] == '\f' || str[count] == '\r' || str[count] == '\n')
	{
		count++;
	}
	if (str[count] == '-' || str[count] == '+')
	{
		if (str[count] == '-')
			sign = -1;
		count++;
	}
	while (ft_isdigit(str[count]))
	{
		result = (result * 10) + (str[count++] - '0');
	}
	return (result * sign);
}
