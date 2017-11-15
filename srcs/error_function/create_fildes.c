/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_fildes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 19:23:23 by jle-quel          #+#    #+#             */
/*   Updated: 2017/11/15 20:26:03 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

/*
*************** TOOLS **********************************************************
*/

static int		ft_errno(char *path, char *err)
{
	ft_printf("42sh: %s: %s\n", path, err);
	return (-1);
}

/*
*************** PRIVATE ********************************************************
*/

static int		test_access(char *path)
{
	if (access(path, X_OK) == -1)
		return (ft_errno(path, "Permission denied"));
	else if (!access(path, X_OK))
		return (ft_errno(path, "Is a directory"));
	return (0);
}

/*
*************** PUBLIC *********************************************************
*/

int 			create_fildes(char *path, int option, int chmod)
{
	int			fd;

	fd = open(path, option, chmod);
	if (fd == -1)
	{
		test_access(path);
		return (-1);
	}
	return (fd);
}
