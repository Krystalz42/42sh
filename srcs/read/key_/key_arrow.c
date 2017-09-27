/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrow.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 03:27:42 by aroulin           #+#    #+#             */
/*   Updated: 2017/08/24 16:29:19 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

int			key_arrow_left(t_read **read_std, unsigned long buff)
{
	if ((*read_std)->history_search && bip())
	{
		memdel_lfh(&((*read_std)->hist_search));
		(*read_std)->print = 2;
	}
	else if ((*read_std)->completion)
		move_completion_left(read_std);
	else if ((*read_std)->cmd->prev && ((*read_std)->history ||
		(!(*read_std)->history && (*read_std)->cmd->prev->c != 10)))
	{
		add_outstanding(NULL, buff, 0);
		(*read_std)->cmd = (*read_std)->cmd->prev;
		(*read_std)->print = 1;
	}
	else
		bip();
	return (1);
}

int			key_arrow_right(t_read **read_std, unsigned long buff)
{
	if ((*read_std)->history_search && bip())
	{
		memdel_lfh(&((*read_std)->hist_search));
		(*read_std)->print = 2;
	}
	else if ((*read_std)->completion)
		move_completion_right(read_std);
	else if ((*read_std)->cmd->next)
	{
		add_outstanding(NULL, buff, 0);
		(*read_std)->cmd = (*read_std)->cmd->next;
		(*read_std)->print = 1;
	}
	else
		bip();
	return (1);
}

int			key_arrow_up(t_read **read_std, unsigned long buff)
{
	(void)buff;
	if ((*read_std)->history_search && bip())
	{
		memdel_lfh(&((*read_std)->hist_search));
		(*read_std)->print = 2;
	}
	else if ((*read_std)->completion)
	{
		move_vertical(read_std, -1);
		(*read_std)->completion++;
	}
	else if (get_len_prompt(-42) != -1)
	{
		(*read_std)->print = 2;
		previous_history(read_std);
	}
	else
		bip();
	return (1);
}

int			key_arrow_down(t_read **read_std, unsigned long buff)
{
	(void)buff;
	if ((*read_std)->history_search && bip())
	{
		memdel_lfh(&((*read_std)->hist_search));
		(*read_std)->print = 2;
	}
	else if ((*read_std)->completion)
	{
		move_vertical(read_std, 1);
		(*read_std)->completion++;
	}
	else if (get_len_prompt(-42) != -1)
	{
		(*read_std)->print = 2;
		next_history(read_std);
	}
	else
		bip();
	return (1);
}
