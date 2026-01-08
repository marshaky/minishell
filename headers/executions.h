/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executions.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaghdal <mnaghdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 13:07:13 by mnaghdal          #+#    #+#             */
/*   Updated: 2025/12/28 15:14:27 by mnaghdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTIONS_H
# define EXECUTIONS_H

# define INT_MAX 2147483647
# define INT_MIN -2147483648
# include <sys/wait.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "../headers/modules.h"
# include "../headers/parsing.h"

void	pwd(void);
void	cd(t_cmd *cmd);
void	echo(t_cmd *cmd);
void	close_prgm(t_cmd *cmd);
void	list_env(void);
void	unset_env(t_cmd *cmd);
void	run_export(t_cmd *cmd);
void	run_builtins(t_cmd *cmd);
void	run_commands(t_cmd *cmd);
t_cmd	*run_pipe_commands(t_cmd *cmds, int *err);
int		handle_redir(t_cmd *cmd);
void	handle_fds(int pfd[2], int red[2], int newpfd[2]);
void	execute_cmd(t_cmd *cmd, int pfd[2], int red[2], int newpfd[2]);

#endif
