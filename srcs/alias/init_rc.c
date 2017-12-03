/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_rc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 22:08:10 by jle-quel          #+#    #+#             */
/*   Updated: 2017/12/03 14:20:38 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

/*
*************** PRIVATE ********************************************************
*/

static void		get_info(const int fd)
{
	char		*str;
	char		**array;

	str = NULL;
	while (get_next_line(fd, &str) > 0)
	{
		if (ft_strchr(str, '=') && (array = ft_strsplit(str, '=')))
		{
			if (arraylen(array) == 2)
				alias_exist(array[0]) == NULL ? add_alias(array) : 0;
			arraydel(&array);
		}
		ft_memdel((void **)&str);
	}
	ft_memdel((void **)&str);
}

static void		fd_err(void)
{
	if (errno == ENOENT)
		error_msg(S42H, "No such file or directory", NULL);
	else if (errno == EACCES)
		error_msg(S42H, "permission denied", NULL);
	else if (errno == ENOTDIR)
		error_msg(S42H, "is a directory", NULL);
}

/*
*************** PUBLIC *********************************************************
*/

void			read_rc(char *str)
{
	int			fd;
	char		*var;
	char		*path;

	if ((var = my_getenv("HOME")))
	{
		path = create_trial_path(var, str);
		if ((fd = open(path, O_RDONLY)) > 0)
		{
			get_info(fd);
			close(fd);
		}
		else
			fd_err();
		ft_memdel((void **)&path);
	}
	else
		error_msg(S42H, "variable HOME not set", NULL);
}

void			init_rc(char *str)
{
	int			fd;
	char		*var;
	char		*path;

	if ((var = my_getenv("HOME")))
	{
		path = create_trial_path(var, str);
		if ((fd = open(path, O_CREAT | O_WRONLY | O_APPEND, 0644)) > 0)
		{
			print_alias(fd, 2);
			close(fd);
		}
		else
			fd_err();
		ft_memdel((void **)&path);
	}
	else
		error_msg(S42H, "variable HOME not set", NULL);
}
