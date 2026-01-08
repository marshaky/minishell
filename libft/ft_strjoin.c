/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marshaky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 14:57:53 by marshaky          #+#    #+#             */
/*   Updated: 2025/12/28 14:57:54 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*holder;
	size_t	count1;
	size_t	count2;

	if (!s1 || !s2)
		return (NULL);
	count1 = 0;
	count2 = 0;
	holder = ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 1), sizeof(char));
	if (holder)
	{
		while (count1 < ft_strlen(s1))
		{
			holder[count1] = s1[count1];
			count1++;
		}
		while (count2 < ft_strlen(s2))
		{
			holder[count1 + count2] = s2[count2];
			count2++;
		}
		return (holder);
	}
	return (NULL);
}
