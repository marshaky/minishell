/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 19:36:27 by marshaky          #+#    #+#             */
/*   Updated: 2025/12/07 19:36:29 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*new_s;
	int		start;
	int		end;

	start = 0;
	end = ft_strlen(s1);
	if (!s1 || s1[0] == '\0')
		return (ft_strdup(""));
	if (set[0] == '\0' || !set)
		return (ft_strdup(s1));
	while (s1[start] != '\0' && ft_strchr(set, s1[start]))
		start++;
	while (end > start && ft_strchr(set, s1[end]))
		end--;
	new_s = ft_substr(s1, start, end - start + 1);
	return (new_s);
}

// #include <stdio.h>
// int main()
// {
// 	char *str = "abcaSimonaa";
// 	char *set = "abc";
// 	char *str2 = ft_strtrim(str, set);
// 	printf("%s", str2);

// }
