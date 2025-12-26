/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 19:36:18 by marshaky          #+#    #+#             */
/*   Updated: 2025/12/07 19:36:20 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	l;

	l = 0;
	i = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[i] != '\0' && i < len)
	{
		l = 0;
		while (needle[l] != '\0' && i + l < len && haystack[i + l] == needle[l])
		{
			if (needle[l + 1] == '\0')
				return ((char *)haystack + i);
			l++;
		}
		i++;
	}
	return (NULL);
}
/*
#include <stdio.h>
#include <string.h>

int main()
{
char s1[] = "Gee for keks";
    char s2[] = "for";
    char* p = ft_strnstr(s1, s2, 15);
    printf("%s\n", p);
	char s[] = "  414121000: thousand";
    char s3[] = "1000: ";
	printf("%s",strnstr("lorem ipsum dolor sit amet", NULL, 10));
}
*/
