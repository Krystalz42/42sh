/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_del.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 06:33:09 by aroulin           #+#    #+#             */
/*   Updated: 2017/10/14 15:53:36 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

t_cmd			*key_del_fct(t_cmd *cmd, unsigned long buff)
{
	t_cmd		*kill;

	if (cmd->prev)
	{
		kill = cmd->prev;
		if (cmd->prev->prev)
		{
			cmd->prev->prev->next = cmd;
			cmd->prev = cmd->prev->prev;
		}
		else
			cmd->prev = NULL;
		if (!buff)
			free(kill);
		else
		{
			kill->next = NULL;
			kill->prev = NULL;
			return (kill);
		}
	}
	return (NULL);
}

int				key_del(t_read **read_std, unsigned long buff)
{
	if ((*read_std)->completion)
	{
		memdel_completion(&((*read_std)->tab_));
		(*read_std)->print = 2;
	}
	if ((*read_std)->history_search)
	{
		key_del_fct((*read_std)->hist_search->cmd, 0);
		compare_history(read_std);
		(*read_std)->history_search++;
	}
	else if ((*read_std)->cmd->prev)
	{
		if ((*read_std)->cmd->prev->c == 10 && !(*read_std)->history)
			return (0);
		add_outstanding(key_del_fct((*read_std)->cmd, buff), buff, 0);
		(*read_std)->print = 2;
	}
	return (1);
}
