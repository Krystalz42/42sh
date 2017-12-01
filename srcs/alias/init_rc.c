/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_rc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 22:08:10 by jle-quel          #+#    #+#             */
/*   Updated: 2017/12/01 19:27:58 by jle-quel         ###   ########.fr       */
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

	while (get_next_line(fd, &str) > 0)
	{
		if (ft_strchr(str, '=') && (array = ft_strsplit(str, '=')))
		{
			if (arraylen(array) == 2)
			{
				alias_exist(array[0]) == NULL ? add_alias(array) : 0;
				arraydel(&array);
			}
		}
		ft_memdel((void **)&str);
	}
	ft_memdel((void **)&str);
}

/*
*************** PUBLIC *********************************************************
*/

void			init_rc(void)
{
	int			fd;
	char		*var;
	char		*path;

	if ((var = my_getenv("HOME")))
	{
		path = create_trial_path(var, ".42sh_rc");
		if ((fd = open(path, O_RDONLY)) > 0)
		{
			get_info(fd);
			close(fd);
		}
		ft_memdel((void **)&path);
	}
}
