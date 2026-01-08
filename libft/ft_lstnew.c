/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marshaky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 14:57:09 by marshaky          #+#    #+#             */
/*   Updated: 2025/12/28 14:57:10 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*result;

	result = ft_calloc(1, sizeof(t_list));
	if (result)
	{
		(*result).content = content;
		(*result).next = NULL;
		return (result);
	}
	return (NULL);
}
