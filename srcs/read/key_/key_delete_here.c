/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_delete_here.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/12 17:36:48 by aroulin           #+#    #+#             */
/*   Updated: 2017/08/19 21:06:32 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

int			key_delete_here(t_read **read_std, unsigned long buff)
{
	t_cmd		*kill;

	if (!(*read_std)->history_search && (*read_std)->cmd->c)
	{
		kill = (*read_std)->cmd;
		(*read_std)->cmd = (*read_std)->cmd->next;
		if ((*read_std)->cmd->prev->prev)
			(*read_std)->cmd->prev->prev->next = (*read_std)->cmd;
		(*read_std)->cmd->prev = (*read_std)->cmd->prev->prev;
		add_outstanding(kill, buff, 0);
		(*read_std)->print = 2;
	}
	else if ((*read_std)->history_search)
	{
		memdel_lfh(&((*read_std)->hist_search));
		(*read_std)->print = 2;
	}
	else if ((*read_std)->completion)
	{
		(*read_std)->print = 2;
		bip();
	}
	else
		bip();
	return (1);
}
