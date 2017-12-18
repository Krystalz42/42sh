/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_less_and.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 13:41:56 by jle-quel          #+#    #+#             */
/*   Updated: 2017/12/18 15:36:39 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

/*
*************** PRIVATE ********************************************************
*/

static int		get_fildes(char *str)
{
	int			fildes;
	
	if (ft_isdigit(*str))
		fildes = ft_atoi(str);
	else
	{
		error_msg(S42H, "ambiguous redirect: ", str);
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

void			op_less_and(t_parsing *node)
{
	int			fildes;
	int			std;

	fildes = get_fildes(node->next->command[0]);
	std = get_std(node->command[0]);
	if (dup2(fildes, std) == -1)
	{
		error_msg(S42H, BAD_FD, NULL);
		exit(1);
	}
	close(fildes);
}
