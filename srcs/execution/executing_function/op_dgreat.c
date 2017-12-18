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
	int			fildes_out;

	fildes_out = STDOUT_FILENO;
	if (ft_isdigit(node->command[0][0]))
		fildes_out = ft_atoi(node->command[0]);
	if (ft_strcmp(node->next->command[0], "-") == 0)
	{
		close_fd(fildes_out);
		return ;
	}
	else if ((fildes = open(node->next->command[0], OPTION_DGREAT, 0644)) == -1)
		check_path(node->next->command[0]);
	if (dup2(fildes, fildes_out) == -1)
		exit(error_msg(S42H, BAD_FD, NULL));
	close(fildes);
}