/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marshaky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 14:56:26 by marshaky          #+#    #+#             */
/*   Updated: 2025/12/28 14:56:27 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	int	length;

	if (!lst || !f)
		return ;
	length = ft_lstsize(lst);
	while (length--)
	{
		f(lst->content);
		lst = lst->next;
	}
}
