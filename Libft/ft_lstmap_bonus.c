/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 19:34:31 by marshaky          #+#    #+#             */
/*   Updated: 2025/12/07 19:34:33 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// void	*f1(void *k)
// {
// 	int i =0;
// 	char 	*str = ft_strdup((char *)k);
// 	if(!str)
// 		return (NULL);
// 	while (str[i] != '\0')
// 	{
// 		if(i % 2 == 0)
// 			str[i] += 32;
// 		i++;
// 	}
// 	return (str);
// }

// void	del1(void *l)
// {
// 	free (l);
// }

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	t_list	*r_node;
	void	*contn;

	result = NULL;
	while (lst)
	{
		if (f)
			contn = (f)(lst->content);
		if (!contn)
		{
			ft_lstclear (&result, del);
			return (NULL);
		}
		r_node = ft_lstnew(contn);
		if (!r_node)
		{
			ft_lstclear (&result, del);
			del(contn);
			return (NULL);
		}
		ft_lstadd_back(&result, r_node);
		lst = lst->next;
	}
	return (result);
}

// # include <stdio.h>

// int main()
// {
// 	t_list	*nod1 = ft_lstnew("SARGIS");
// 	t_list	*nod2 = ft_lstnew("SRO");
// 	t_list	*nod3 = ft_lstnew("ACCHGF");

// 	nod1->next = nod2;
// 	nod2->next = nod3;
// 	t_list *all = nod1;

// 	t_list	*map = ft_lstmap(all, &f1, &del1);
// 	t_list *cur = map;

// 	while (cur)
// 	{
// 		printf("%s\n", cur->content);
// 		cur=cur->next;
// 	}

// 	ft_lstclear(&all, del1);
// 	ft_lstclear(&cur, del1);
// }
