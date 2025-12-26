/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 19:34:36 by marshaky          #+#    #+#             */
/*   Updated: 2025/12/07 19:34:36 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new2;

	new2 = (t_list *)malloc(sizeof(t_list));
	if (!new2)
		return (NULL);
	new2->content = content;
	new2->next = NULL;
	return (new2);
}
