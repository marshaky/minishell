/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marshaky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 14:58:03 by marshaky          #+#    #+#             */
/*   Updated: 2025/12/28 14:58:04 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*result;
	int		length;
	int		count;

	if (!s || !f)
		return (NULL);
	count = 0;
	length = ft_strlen(s);
	result = ft_calloc(length + 1, sizeof(char));
	if (result)
	{
		ft_memcpy(result, s, length);
		while (count < length)
		{
			result[count] = f(count, result[count]);
			count++;
		}
		return (result);
	}
	return (NULL);
}
