/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaghdal <mnaghdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 18:19:56 by mnaghdal          #+#    #+#             */
/*   Updated: 2025/12/28 15:13:07 by mnaghdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/modules.h"

void	*ft_realloc(void *ptr, size_t size)
{
	void	*result;

	result = ft_calloc(1, size);
	ft_memcpy(result, ptr, size);
	free(ptr);
	return (result);
}
