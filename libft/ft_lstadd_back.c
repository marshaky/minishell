/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marshaky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 14:56:15 by marshaky          #+#    #+#             */
/*   Updated: 2025/12/28 14:56:16 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*lastnode;

	if (lst && new)
	{
		if (!*lst)
		{
			*lst = new;
		}
		else
		{
			lastnode = ft_lstlast(*lst);
			(*lastnode).next = new;
		}
	}
}
