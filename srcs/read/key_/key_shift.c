/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 06:34:02 by aroulin           #+#    #+#             */
/*   Updated: 2017/11/17 16:40:38 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

int		key_shift_up(t_read **read_std, unsigned long buff)
{
	int		co;

	if ((*read_std)->history_search)
	{
		(*read_std)->print = 2;
		memdel_lfh(&((*read_std)->hist_search));
	}
	else if ((*read_std)->completion)
	{
		memdel_completion(&((*read_std)->tab_));
		(*read_std)->print = 2;
	}
	else
		(*read_std)->print = 1;
	co = tgetco();
	if (co)
		while (co-- && (*read_std)->cmd->prev)
		{
			if (!(*read_std)->history && (*read_std)->cmd->prev->c == 10)
				break ;
			(*read_std)->cmd = (*read_std)->cmd->prev;
		}
	add_outstanding(NULL, buff, 0);
	return (1);
}

int		key_shift_down(t_read **read_std, unsigned long buff)
{
	int		co;

	if ((*read_std)->history_search)
	{
		(*read_std)->print = 2;
		memdel_lfh(&((*read_std)->hist_search));
	}
	else if ((*read_std)->completion)
	{
		memdel_completion(&((*read_std)->tab_));
		(*read_std)->print = 2;
	}
	else
		(*read_std)->print = 1;
	co = tgetco();
	if (co)
		while (co-- && (*read_std)->cmd->next)
			(*read_std)->cmd = (*read_std)->cmd->next;
	add_outstanding(NULL, buff, 0);
	return (1);
}

int		key_shift_left(t_read **read_std, unsigned long buff)
{
	if ((*read_std)->history_search)
	{
		(*read_std)->print = 2;
		memdel_lfh(&((*read_std)->hist_search));
	}
	else if ((*read_std)->completion)
	{
		memdel_completion(&((*read_std)->tab_));
		(*read_std)->print = 2;
	}
	else
		(*read_std)->print = 1;
	while ((*read_std)->cmd->prev && (*read_std)->cmd->prev->c == 32)
		(*read_std)->cmd = (*read_std)->cmd->prev;
	while ((*read_std)->cmd->prev)
	{
		if ((*read_std)->cmd->prev->c == 32)
			break ;
		(*read_std)->cmd = (*read_std)->cmd->prev;
	}
	add_outstanding(NULL, buff, 0);
	return (1);
}

int		key_shift_right(t_read **read_std, unsigned long buff)
{
	if ((*read_std)->history_search)
	{
		(*read_std)->print = 2;
		memdel_lfh(&((*read_std)->hist_search));
	}
	else if ((*read_std)->completion)
	{
		memdel_completion(&((*read_std)->tab_));
		(*read_std)->print = 2;
	}
	else
		(*read_std)->print = 1;
	while ((*read_std)->cmd->c)
	{
		if ((*read_std)->cmd->c == 32)
			break ;
		(*read_std)->cmd = (*read_std)->cmd->next;
	}
	while ((*read_std)->cmd->c && (*read_std)->cmd->c == 32)
		(*read_std)->cmd = (*read_std)->cmd->next;
	add_outstanding(NULL, buff, 0);
	return (1);
}
