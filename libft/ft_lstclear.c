/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marshaky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 14:56:20 by marshaky          #+#    #+#             */
/*   Updated: 2025/12/28 14:56:21 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	int		length;
	t_list	*temp;

	if (!lst || !del)
		return ;
	length = ft_lstsize(*lst);
	while (length--)
	{
		del((*lst)->content);
		temp = (*lst)->next;
		(*lst)->next = NULL;
		free(*lst);
		*lst = temp;
	}
}
