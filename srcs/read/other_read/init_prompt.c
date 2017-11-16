/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_prompt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 17:45:51 by aroulin           #+#    #+#             */
/*   Updated: 2017/09/14 17:45:52 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

static int 				my_getbranch(void)
{
	pid_t		father;
	int			status;
	int			fildes[2];

	if ((father = fork()) == -1)
		return (-1);
	else if (father > 0)
	{
		waitpid(father, &status, 0);
		if (WIFEXITED(status) && WEXITSTATUS(status))
		{
			remove("/tmp/.gitbranch");
			return (1);
		}
	}
	else
	{
		set_termios(SET_OUR_TERM);
		fildes[1] = open("/dev/null", O_WRONLY);
		dup2(fildes[1], STDERR_FILENO);
		fildes[0] = open("/tmp/.gitbranch", O_CREAT | O_WRONLY, 0644);
		dup2(fildes[0], STDOUT_FILENO);
		execve("/usr/bin/git", (char *[]){"git", "branch", NULL}, NULL);
		close_pipe(fildes);
	}
	return (0);
}

static char				*read_branch(void)
{
	char			*branch;
	char			*real_branch;
	int				fildes;

	branch = NULL;
	real_branch = NULL;
	if (my_getbranch() || (fildes = open("/tmp/.gitbranch", O_RDONLY)) == -1)
		return (NULL);
	my_gnl(fildes, &branch);
	close(fildes);
	if (branch)
	{
		real_branch = (char *)ft_memalloc(sizeof(char) * (ft_strlen(branch) + 5));
		ft_strcpy(real_branch + ft_strlen(real_branch)," [");
		ft_strcpy(real_branch + ft_strlen(real_branch), branch + 2);
		ft_strcpy(real_branch + ft_strlen(real_branch), "] ");
		free((void *)branch);
	}
	return (real_branch);
}

static char				*my_getcwd(void)
{
	char			str[PATH_MAX];
	size_t			len;

	if (getcwd(str, PATH_MAX))
	{
		if (!ft_strcmp(str, "/"))
			return (ft_strdup(str));
		len = ft_strlen(str) - 1;
		while (str[len] && str[len] != '/')
			len--;
		return (ft_strdup(str + (len + 1)));
	}
	return (NULL);
}

static char 			*my_color(void)
{
	static int 		color = 255;
	static bool		dir = false;

	dir = (color == 237) ? true : dir;
	dir = (color == 255) ? false : dir;
	color = (dir) ? color + 1 : color - 1;
	return (ft_itoa(color));
}

void				init_prompt(void)
{
	static char		*prompt;
	char			*path;
	char			*color;
	char			*branch;

	branch = read_branch();
	path = my_getcwd();
	color = my_color();
	ft_memdel((void **)&prompt);
	prompt = (char *)ft_memalloc(sizeof(char) * (27 + ft_strlen(path) + ft_strlen(branch)));
	ft_memcpy(prompt + ft_strlen(prompt), "\e[38;5;", 10);
	ft_strcpy(prompt + ft_strlen(prompt), color);
	ft_strcpy(prompt + ft_strlen(prompt), "m");
	ft_strcpy(prompt + ft_strlen(prompt), path);
	ft_strcpy(prompt + ft_strlen(prompt), branch);
	ft_strcpy(prompt + ft_strlen(prompt), var_return(-1) ? RED : GRN);
	ft_strcpy(prompt + ft_strlen(prompt), var_return(-1) ? " ✗ " : " √ ");
	ft_strcpy(prompt + ft_strlen(prompt), "\x1B[0m");
	my_prompt(prompt);
	get_len_prompt((int)(ft_strlen(path) + 3));
	free((void *)path);
	free((void *)color);
	free((void *)branch);
}
