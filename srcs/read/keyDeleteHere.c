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

int			keyDeleteHere(t_read **readStd)
{
	t_cmd		*kill;

	if ((*readStd)->cmd->c)
	{
		kill = (*readStd)->cmd;
		(*readStd)->cmd = (*readStd)->cmd->next;
		if ((*readStd)->cmd->prev->prev)
			(*readStd)->cmd->prev->prev->next = (*readStd)->cmd;
		(*readStd)->cmd->prev = (*readStd)->cmd->prev->prev;
		free(kill);
	}
	return (1);
}
