/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_great.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 15:19:54 by jle-quel          #+#    #+#             */
/*   Updated: 2017/12/20 14:46:40 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

void					op_great(t_parsing *node)
{
	int			std;
	int			fildes;

	if ((fildes = open(node->next->command[0], OPTION_GREAT, 0644)) == -1)
		check_path(node->next->command[0]);
	else
	{
		if (ft_strchr(node->command[0], '&'))
		{
			dup2(fildes, STDOUT_FILENO);
			dup2(fildes, STDERR_FILENO);
		}
		else
		{
			std = STDOUT_FILENO;
			if (ft_isdigit(node->command[0][0]))
				std = ft_atoi(node->command[0]);
			dup2(fildes, std);
		}
		close(fildes);
	}
}
