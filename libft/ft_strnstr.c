/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marshaky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 14:58:07 by marshaky          #+#    #+#             */
/*   Updated: 2025/12/28 14:58:08 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	little_length;
	size_t	count;

	count = 0;
	little_length = ft_strlen(little);
	if (little[0] == '\0')
		return ((char *) big);
	if (!big && !len)
		return (NULL);
	if (ft_strlen(big) < len)
		len = ft_strlen(big);
	while (count < len && big[count])
	{
		if (big[count] == little[0])
		{
			if (!ft_strncmp(big + count, little, little_length))
			{
				if ((little_length + count) > len)
					return (NULL);
				return ((char *)(big + count));
			}
		}
		count++;
	}
	return (NULL);
}
