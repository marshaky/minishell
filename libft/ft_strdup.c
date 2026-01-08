/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marshaky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 14:57:48 by marshaky          #+#    #+#             */
/*   Updated: 2025/12/28 14:57:49 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		length;
	int		count;
	char	*result;

	length = ft_strlen(s1);
	result = ft_calloc((length + 1), sizeof(char));
	count = 0;
	if (result)
	{
		while (count < (length))
		{
			result[count] = s1[count];
			count++;
		}
		return (result);
	}
	return (NULL);
}
