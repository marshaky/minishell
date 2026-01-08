/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marshaky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 14:56:30 by marshaky          #+#    #+#             */
/*   Updated: 2025/12/28 14:56:31 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	int	length;

	if (!lst)
		return (NULL);
	length = ft_lstsize(lst);
	while (length-- > 1)
	{
		lst = lst->next;
	}
	return (lst);
}
