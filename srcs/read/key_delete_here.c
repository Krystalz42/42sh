/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_delete_here.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/12 17:36:48 by aroulin           #+#    #+#             */
/*   Updated: 2017/08/19 20:37:10 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

int			delete_char_here(t_read **read_std)
{
	t_cmd		*kill;

	if ((*read_std)->cmd->c)
	{
		kill = (*read_std)->cmd;
		(*read_std)->cmd = (*read_std)->cmd->next;
		if ((*read_std)->cmd->prev->prev)
			(*read_std)->cmd->prev->prev->next = (*read_std)->cmd;
		(*read_std)->cmd->prev = (*read_std)->cmd->prev->prev;
		free(kill);
	}
	return (1);
}
