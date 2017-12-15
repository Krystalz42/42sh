/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_dless.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 16:14:51 by jle-quel          #+#    #+#             */
/*   Updated: 2017/12/15 19:20:56 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

/*
*************** PRIVATE ********************************************************
*/

static int		get_fildes(char *str)
{
	int			fildes;

	if ((fildes = open(str, O_RDONLY)) == -1)
	{
		check_path(str);
		exit(1);
	}
	return (fildes);
}

/*
*************** PUBLIC *********************************************************
*/

void			op_dless(t_parsing *node)
{
	int			fildes;

	fildes = get_fildes(node->heredoc);
	if (dup2(fildes, STDIN_FILENO) == -1)
	{
		error_msg(S42H, BAD_FD, NULL);
		exit(1);
	}
	close(fildes);
	remove(node->heredoc);
}
