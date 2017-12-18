/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_great_and.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 16:10:18 by jle-quel          #+#    #+#             */
/*   Updated: 2017/11/20 23:36:40 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

/*
*************** PRIVATE ********************************************************
*/

static int		get_fildes(int fildes, char *str)
{
	int			fildes_out;

	if (!ft_strcmp(str, "-"))
	{
		close(fildes);
		return (-1);
	}
	else if (ft_strisdigit(str))
		fildes_out = ft_atoi(str);
	else
		if ((fildes_out = open(str, OPTION_GREAT, 0644)) == -1)
			check_path(str);
	return (fildes_out);
}

/*
*************** PUBLIC *********************************************************
*/

int 			op_great_and(t_parsing *node)
{
	int		fildes_out;
	int		fildes_in;

	fildes_in = STDOUT_FILENO;
	if (ft_isdigit(node->command[0][0]))
		fildes_in = ft_atoi(node->command[0]);
	if ((fildes_out = get_fildes(fildes_in, node->next->command[0])) == -1)
		return (1);
	if (dup2(fildes_out, fildes_in) == -1)
	{
		error_msg(S42H, BAD_FD, NULL);
		return (0);
	}
	return (1);
}