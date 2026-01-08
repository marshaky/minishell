/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marshaky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 14:57:25 by marshaky          #+#    #+#             */
/*   Updated: 2025/12/28 14:57:26 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *txt, int c, size_t len)
{
	unsigned char	*holder;
	size_t			count;

	count = 0;
	holder = (unsigned char *)txt;
	while (count < len)
	{
		holder[count++] = (unsigned char) c;
	}
	return (txt);
}
