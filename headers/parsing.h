/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaghdal <mnaghdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 15:00:50 by marshaky          #+#    #+#             */
/*   Updated: 2025/12/28 15:12:14 by mnaghdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <signal.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include "../libft/libft.h"
# include "../headers/modules.h"

typedef struct cmd_data
{
	char			*cmd;
	char			*exec;
	char			**args;
	char			**redir_files;
	char			**redir_sym;
	char			*sep;
	char			*heredoc_data;
	int				error;
	int				prev_error;
	pid_t			process_id;
	struct cmd_data	*next;
}	t_cmd;

t_cmd	*allocate_cmd_node(char *whole_command);
t_cmd	*last_cmd_node(t_cmd *head);
t_cmd	*previous_cmd_node(t_cmd *head, t_cmd *current_node);
t_cmd	*append_cmd_to_tree(t_cmd *head, t_cmd *new_command);
t_cmd	*remove_cmd_from_tree(t_cmd *head, t_cmd *todelete);
void	erase_cmd_node(t_cmd *cmd_pointer);
void	free_cmd_tree(t_cmd *head);
t_cmd	*input_split(char *input, int *err);
int		check_separator(t_cmd *cmd);
char	**parse_args(char *cmd);
char	**extract_redir(char *cmd);
int		is_builtin(char *exec);
char	*get_relative_path(char *exec);
char	*get_absolute_path(char *exec);
char	*parse_exec(char *cmd, int *err);
char	*clean_quotes(char *str);
int		parse_redir(t_cmd *cmd);
void	parsing(t_cmd *cmd);
char	*replace_variables(char *str, int err);
t_cmd	*get_next_cmd(t_cmd *head, int *err);
void	manage_heredoc(t_cmd *cmds);

#endif
