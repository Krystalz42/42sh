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
	int			std;
	int			fildes;

	ft_putstr("dsadsa");
	std = STDOUT_FILENO;
	if (ft_isdigit(node->command[0][0]))
		std = ft_atoi(node->command[0]);
	if ((fildes = open(node->next->command[0], OPTION_DGREAT, 0644)) == -1)
		check_path(node->next->command[0]);
	else
	{
		fildes = check_fd(fildes);
		dup2(fildes, std);
		close(fildes);
	}
}