/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaghdal <mnaghdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 13:15:30 by mnaghdal          #+#    #+#             */
/*   Updated: 2025/12/28 15:16:47 by mnaghdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# define INT_MAX 2147483647
# define INT_MIN -2147483648
# include "../libft/libft.h"
# include "../headers/parsing.h"
# include "../headers/executions.h"
# include <signal.h>

void	sig_handler(int sign);
int		is_spaces(char *str);
#endif
