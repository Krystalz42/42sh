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

void 			op_great_and(t_parsing *node)
{
	int		fildes_out;
	int		fildes;

	fildes = STDOUT_FILENO;
	if (ft_isdigit(node->command[0][0]))
		fildes = ft_atoi(node->command[0]);
	if ((fildes_out = get_fildes(fildes, node->next->command[0])) < 0)
		return ;
	if (dup2(fildes_out, fildes) == -1)
		exit(error_msg(S42H, BAD_FD, NULL));
}