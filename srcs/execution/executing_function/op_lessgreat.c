/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_lessgreat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 17:11:52 by jle-quel          #+#    #+#             */
/*   Updated: 2017/12/18 15:26:23 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

/*
*************** PRIVATE ********************************************************
*/

static int		get_fildes(char *str)
{
	int			fildes;

	if ((fildes = open(str, O_RDWR | O_CREAT, 0644)) == -1)
	{
		check_path(str);
		exit(1);
	}
	return (fildes);
}

static int		get_std(char *str)
{
	int			std;

	if (ft_isdigit(*str))
		std = ft_atoi(str);
	else
		std = STDIN_FILENO;
	return (std);
}

/*
*************** PUBLIC *********************************************************
*/

void			op_lessgreat(t_parsing *node)
{
	int			fildes;
	int			std;

	if ((fildes = get_fildes(node->next->command[0])) == -1)
		exit(1);
	std = get_std(node->command[0]);
	if (dup2(fildes, std) == -1)
	{
		error_msg(S42H, BAD_FD, NULL);
		exit(1);
	}
	close(fildes);
}
