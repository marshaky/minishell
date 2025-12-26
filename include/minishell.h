/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 23:09:55 by marshaky          #+#    #+#             */
/*   Updated: 2025/12/26 04:53:32 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../Libft/libft.h"
# include <stdio.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <signal.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <errno.h>

extern int	g_signal;

void	print_error(const char *msg);
char	**copy_env(char **envp);
char	*get_env_value(const char *name, char **envp);
int		add_env_var(const char *var, char ***envp);
int		find_env_var(const char *name, char **envp);
int		match_var(const char *env_var, const char *name);
char	**update_lvl(char **envp);
int		path_type(const char *p);
void	print_error(const char *msg);
int		is_operator(char c);
int		ft_isspace(char c);
void	free_dp(char **dp);
int		dp_count(char **dp);
char	*get_token(const char **p, char **envp);
int		ft_isspace(char c);
int		validate_tokens(char **tokens);
char	**tokenize(const char *input, char **envp);
void	ft_echo(char **args);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_cd(char **args, char **envp);
void	ft_pwd(void);
int		ft_export(char **tokens, char ***envp);
void	ft_env(char **envp);
void	ft_exit(char **args);
void	ft_unset(char **args, char ***envp);
int		inner_cmd(char **tokens, char ***envp);
int		execute_line(char **tokens, char ***envp);
int		valid_var(const char *name);
void	sigint_handler(int sig);
void    remove_empty_tokens(char ***tokens);

#endif
