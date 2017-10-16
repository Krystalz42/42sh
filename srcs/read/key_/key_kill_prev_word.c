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
	t_cmd   *tmp;

	tmp = (*read_std)->cmd->prev;
	if (tmp)
	{
		tmp->next = NULL;
		while (tmp->prev && tmp->prev->c == 32)
			tmp = tmp->prev;
		while (tmp->prev && ft_isalnum(tmp->prev->c))
			tmp = tmp->prev;
		(*read_std)->cmd->prev = (tmp->prev) ? (tmp->prev) : NULL;
		tmp->prev = NULL;
		add_outstanding(tmp, buff, 0);
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