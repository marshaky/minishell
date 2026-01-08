/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modules.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaghdal <mnaghdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 18:20:02 by mnaghdal          #+#    #+#             */
/*   Updated: 2025/12/28 14:34:54 by mnaghdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODULES_H
# define MODULES_H

# include "../libft/libft.h"
# include <readline/readline.h>
# include <readline/history.h>

typedef struct env_vars
{
	char			*name;
	char			*value;
	int				hide;
	struct env_vars	*next;
}	t_env;

extern t_env	*g_env;
void	*ft_realloc(void *ptr, size_t size);
char	*fetch(char *var_name);
char	*get_work_dir(void);
char	*get_host_name(void);
char	*get_branch_name(void);
char	*prompt_msg(void);
char	*prompt(void);
char	*replace_word(char *str, char *w0, char *w1, int usefree);
char	*replace_all_words(char *str, char *w0, char *w1, int usefree);
t_env	*add_env(t_env *head, char *name, char *value);
t_env	*last_env(t_env *head);
t_env	*find_env(t_env *head, char *name);
void	destory_all_env(t_env *head);
void	free2d(void **ptr);
void	env_init(int argc, char **argv, char **env);
char	**export_env(void);

#endif
