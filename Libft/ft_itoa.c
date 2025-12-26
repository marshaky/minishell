/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 19:33:59 by marshaky          #+#    #+#             */
/*   Updated: 2025/12/07 19:34:00 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count(int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		n = -n;
		i++;
	}
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*it;
	int		nb;
	int		size;

	size = count(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	it = (char *)malloc(size + 1);
	if (!it)
		return (NULL);
	if (n < 0)
	{
		n = -n;
		it[0] = '-';
	}
	it[size--] = '\0';
	while (n != 0)
	{
		nb = n % 10;
		it[size--] = nb + '0';
		n = n / 10;
	}
	return (it);
}
