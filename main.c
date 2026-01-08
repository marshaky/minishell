/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaghdal <mnaghdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 13:15:25 by mnaghdal          #+#    #+#             */
/*   Updated: 2025/12/28 15:07:48 by mnaghdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/main.h"

void	sig_handler(int sign)
{
	if (sign == SIGINT)
	{
		write(1, "\n", 1);
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
}

void	struct_execution(t_cmd *head, int *err)
{
	while (head)
	{
		if (head->sep && head->sep[0] == '|')
			head = run_pipe_commands(head, err);
		else
			run_commands(head);
		head = get_next_cmd(head, err);
	}
}

int	is_spaces(char *str)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (str[++i])
	{
		if (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
			|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
			j++;
	}
	if (j == i || i == 0)
		return (-1);
	return (0);
}

static char	*get_valid_input(void)
{
	char	*input;

	while (1)
	{
		input = prompt();
		if (!input)
		{
			printf("exit\n");
			close_prgm(NULL);
		}
		if (!is_spaces(input))
			return (input);
		free(input);
	}
}

int	main(int argc, char **argv, char **env)
{
	int		err;
	char	*input;
	t_cmd	*cmds;

	env_init(argc, argv, env);
	signal(SIGINT, sig_handler);
	signal(SIGQUIT, SIG_IGN);
	err = 0;
	while (1)
	{
		input = get_valid_input();
		add_history(input);
		cmds = input_split(input, &err);
		if (cmds)
			cmds->prev_error = err;
		parsing(cmds);
		free(input);
		struct_execution(cmds, &err);
	}
	return (0);
}
