/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 19:36:11 by marshaky          #+#    #+#             */
/*   Updated: 2025/12/07 19:36:13 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*ss;
	unsigned int	i;

	i = 0;
	ss = (char *)malloc(ft_strlen(s) * sizeof(char) + 1);
	if (!ss)
		return (NULL);
	while (s[i] != '\0')
	{
		ss[i] = f(i, s[i]);
		i++;
	}
	ss[i] = '\0';
	return (ss);
}
