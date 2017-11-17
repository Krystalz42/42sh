/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_reprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 16:48:14 by aroulin           #+#    #+#             */
/*   Updated: 2017/11/17 16:50:06 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

int		key_reprint(t_read **read_std, unsigned long buff)
{
	t_outstanding		*undo;
	t_cmd				*keep;

	(void)buff;
	undo = get_os_pointer(NULL, 0);
	if (undo->cmd)
	{
		keep = undo->cmd;
		undo->cmd->prev = (*read_std)->cmd->prev;
		undo->cmd->prev && (undo->cmd->prev->next = undo->cmd);
		while (undo->cmd->next)
			undo->cmd = undo->cmd->next;
		undo->cmd->next = (*read_std)->cmd;
		undo->cmd->next->prev = undo->cmd;
		(*read_std)->print = 2;
	}
	return (1);
}
