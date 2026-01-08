/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free2d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaghdal <mnaghdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 18:19:52 by mnaghdal          #+#    #+#             */
/*   Updated: 2025/12/28 15:12:55 by mnaghdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/modules.h"

void	free2d(void **ptr)
{
	int	index;

	index = 0;
	while (ptr && ptr[index])
		free(ptr[index++]);
	free(ptr);
}
