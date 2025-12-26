/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 19:35:33 by marshaky          #+#    #+#             */
/*   Updated: 2025/12/07 19:35:33 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_word_count(const char *s, char c)
{
	size_t	count;
	int		in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s == c)
			in_word = 0;
		else if (!in_word)
		{
			in_word = 1;
			count++;
		}
		s++;
	}
	return (count);
}

static size_t	ft_word_len(const char *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static char	*ft_strndup(const char *s, size_t n)
{
	char	*dup;
	size_t	i;

	i = 0;
	dup = (char *)malloc(n + 1);
	if (!dup)
		return (NULL);
	while (i < n)
	{
		dup[i] = s[i];
		i++;
	}
	dup[n] = '\0';
	return (dup);
}

static void	ft_arr_free(char **arr, size_t i)
{
	while (i--)
		free(arr[i]);
	free(arr);
}

char	**ft_split(const char *s, char c)
{
	char	**arr;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	arr = (char **)malloc(sizeof(char *) * (ft_word_count(s, c) + 1));
	if (!arr)
		return (NULL);
	while (*s)
	{
		if (*s != c)
		{
			arr[i] = ft_strndup(s, ft_word_len(s, c));
			if (!arr[i])
				return (ft_arr_free(arr, i), NULL);
			i++;
			s += ft_word_len(s, c);
		}
		else
			s++;
	}
	arr[i] = NULL;
	return (arr);
}

// #include <stdio.h>
// #include <stdlib.h>
//  int main()
//  {
// 	printf("'%d'\n",count("lorem", ' '));
//      int i = 0;
//     char **res = ft_split("hello!", 32:' ');
//      while (res[i])
//      {
//          printf("'%s'\n",res[i]);
//          i++;
//      }

//  return (0);
//  }
