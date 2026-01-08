/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_prgm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaghdal <mnaghdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 13:06:48 by mnaghdal          #+#    #+#             */
/*   Updated: 2025/12/28 15:09:09 by mnaghdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/executions.h"

static long long	parse_num(char *str, int *err)
{
	int			dig;
	int			sign;
	long long	result;

	sign = 1;
	result = 0;
	if (str[0] == '-' || str[0] == '+')
	{
		if (str[0] == '-')
			sign = -1;
		str++;
	}
	while (str && !*err && str[0] >= '0' && str[0] <= '9')
	{
		dig = (str[0] - '0');
		if (result > 922337203685477580
			|| (result == 922337203685477580 && dig > 7 && sign == 1)
			|| (result == 922337203685477580 && dig > 8 && sign == -1))
			*err = 1;
		result = (result * 10) + dig;
		str++;
	}
	return (result * sign);
}

static int	extract_err_code(char *code)
{
	int			err;
	long long	i;

	if (!code)
		return (-1);
	i = -1;
	if (code[0] == '-' || code[0] == '+')
		i++;
	while (code[++i])
	{
		if (code[i] < '0' || code[i] > '9')
		{
			ft_putstr_fd("exit: numeric argument required\n", 2);
			return (255);
		}
	}
	err = 0;
	i = parse_num(code, &err);
	if (err)
	{
		ft_putstr_fd("exit: numeric argument required\n", 2);
		return (255);
	}
	return ((size_t)i % 256);
}

void	close_prgm(t_cmd *cmd)
{
	int		errnm;

	if (!cmd)
		exit(0);
	if (cmd->args[1] && cmd->args[2])
	{
		ft_putstr_fd("exit: too many arguments\n", 2);
		cmd->error = 1;
		return ;
	}
	rl_clear_history();
	destory_all_env(g_env);
	errnm = extract_err_code(cmd->args[1]);
	if (errnm < 0)
		errnm = cmd->prev_error;
	free_cmd_tree(cmd);
	printf("exit\n");
	exit(errnm);
}
