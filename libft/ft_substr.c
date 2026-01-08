/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marshaky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 14:58:14 by marshaky          #+#    #+#             */
/*   Updated: 2025/12/28 14:58:15 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	count;
	char	*result;

	if (!s || start >= ft_strlen(s))
		return (ft_calloc(1, sizeof(char)));
	if (len > ft_strlen(s))
		len = ft_strlen(s) - start;
	result = ft_calloc((len + 1), sizeof(char));
	if (!result)
		return (NULL);
	count = 0;
	while (count < len && s[start + count])
	{
		result[count] = s[start + count];
		count++;
	}
	return (result);
}
