/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_dgreat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 16:11:44 by jle-quel          #+#    #+#             */
/*   Updated: 2017/11/20 23:38:46 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

void				op_dgreat(t_parsing *node)
{
	int			fildes;
	
	if ((fildes = open(node->next->command[0], OPTION_DGREAT, 0644)) == -1)
		check_path(node->next->command[0]);
	else
	{
		if (ft_isdigit(node->command[0][0]))
			dup2(fildes, ft_atoi(node->command[0]));
		else if (node->command[0][0] == '&')
		{
			dup2(fildes, STDOUT_FILENO);
			dup2(fildes, STDERR_FILENO);
		}
		else
			dup2(fildes, STDOUT_FILENO);
		close(fildes);
	}
}