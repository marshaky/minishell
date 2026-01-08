/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaghdal <mnaghdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 18:20:09 by mnaghdal          #+#    #+#             */
/*   Updated: 2025/12/28 15:13:22 by mnaghdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/modules.h"
#include <fcntl.h>

char	*get_work_dir(void)
{
	char	*home_dir;
	char	*work_dir;
	size_t	work_len;
	size_t	home_len;

	home_dir = fetch("HOME");
	work_dir = getcwd(NULL, 0);
	home_len = ft_strlen(home_dir) - 1;
	work_len = ft_strlen(work_dir);
	if (!work_dir)
		return (NULL);
	if (home_dir && !ft_strncmp(work_dir, home_dir, home_len))
	{
		home_dir = ft_substr(work_dir, home_len, (work_len - home_len));
		home_dir[0] = '~';
		free(work_dir);
		return (home_dir);
	}
	return (work_dir);
}

char	*get_host_name(void)
{
	int		fd;
	char	*buff;

	buff = NULL;
	fd = open("/etc/hostname", O_RDONLY);
	if (fd > 0)
	{
		buff = ft_calloc(1024, 1);
		read(fd, buff, 1024);
	}
	close(fd);
	if (buff && buff[ft_strlen(buff)-1] == '\n')
		buff[ft_strlen(buff) - 1] = '\0';
	return (buff);
}

char	*get_branch_name(void)
{
	int		fd;
	char	**temp;
	char	*result;

	result = NULL;
	fd = open(".git/HEAD", O_RDONLY);
	if (fd > 0)
	{
		result = ft_calloc(1024, 1);
		read(fd, result, 1024);
		close(fd);
	}
	if (result)
	{
		fd = -1;
		temp = ft_split(result, '/');
		free(result);
		while (temp[++fd])
			result = temp[fd];
		result[ft_strlen(result) - 1] = '\0';
		result = replace_all_words(" (b)", "b", result, 0);
		free2d((void **)temp);
	}
	return (result);
}

char	*prompt_msg(void)
{
	return (ft_strdup("\e[1;35mminishell$\e[0m "));
}

char	*prompt(void)
{
	char	*input;
	char	*prompt_txt;

	prompt_txt = prompt_msg();
	input = readline(prompt_txt);
	free(prompt_txt);
	return (input);
}
