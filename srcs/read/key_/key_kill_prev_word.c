/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_kill_prev_word.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 19:25:40 by aroulin           #+#    #+#             */
/*   Updated: 2017/09/25 19:25:41 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

static void			kill_prev_word(t_read **read_std, unsigned long buff)
{
	t_cmd		*temp;

	temp = (*read_std)->cmd->prev;
	if (temp)
	{
		temp->next = NULL;
		while (temp->prev && temp->prev->c == 32)
			temp = temp->prev;
		while (temp->prev && ft_isalnum(temp->prev->c))
			temp = temp->prev;
		(*read_std)->cmd->prev = (temp->prev) ? (temp->prev) : NULL;
		if ((*read_std)->cmd->prev)
			(*read_std)->cmd->prev->next = (*read_std)->cmd;
		temp->prev = NULL;
		add_outstanding(temp, buff, 0);
		(*read_std)->print = 2;
	}
}

int					key_kill_prev_word(t_read **read_std, unsigned long buff)
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
	if ((*read_std)->cmd->prev)
		kill_prev_word(read_std, buff);
	return (1);
}