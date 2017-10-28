/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_kill_k.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 18:07:22 by aroulin           #+#    #+#             */
/*   Updated: 2017/09/25 18:07:24 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

static void		kill_k(t_read **read_std, unsigned long buff)
{
	t_cmd		*kill;
	t_cmd		*tmp;

	kill = (*read_std)->cmd;
	tmp = (*read_std)->cmd;
	while (tmp->next->c)
		tmp = tmp->next;
	if ((*read_std)->cmd->prev)
		(*read_std)->cmd->prev->next = tmp->next;
	tmp->next->prev = (*read_std)->cmd->prev;
	(*read_std)->cmd = tmp->next;
	(*read_std)->print = 2;
	kill->prev = NULL;
	tmp->next = NULL;
	add_outstanding(kill, buff, 0);
}

int				key_kill_k(t_read **read_std, unsigned long buff)
{
	if ((*read_std)->completion)
	{
		(*read_std)->print = 2;
		memdel_completion(&((*read_std)->tab_));
	}
	else if  ((*read_std)->history_search)
	{
		(*read_std)->print = 2;
		memdel_lfh(&((*read_std)->hist_search));
	}
	if ((*read_std)->cmd->c)
		kill_k(read_std, buff);
	return (1);
}