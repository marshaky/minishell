/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marshaky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 14:55:54 by marshaky          #+#    #+#             */
/*   Updated: 2025/12/28 14:55:55 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*holder;

	holder = malloc(count * size);
	if (holder)
	{
		ft_bzero(holder, count * size);
		return (holder);
	}
	return (NULL);
}
