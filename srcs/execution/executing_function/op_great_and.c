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

static int		get_fildes(char *str)
{
	int			fildes;

	if (!ft_strcmp(str, "-"))
		fildes = open(PATH_ERROR, O_WRONLY);
	else if (ft_strisdigit(str))
		fildes = ft_atoi(str);
	else
		if ((fildes = open(str, OPTION_GREAT, 0644)) == -1)
			check_path(str);
	return (fildes);
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
	fildes_out = get_fildes(node->next->command[0]);
	if (dup2(fildes_out, fildes_in) == -1)
	{
		error_msg(S42H, BAD_FD, NULL);
		return (0);
	}
	return (1);
}