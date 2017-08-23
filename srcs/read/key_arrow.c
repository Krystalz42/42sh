/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrow.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 03:27:42 by aroulin           #+#    #+#             */
/*   Updated: 2017/08/22 23:47:47 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

int			arrow_left(t_read **read_std)
{
	if ((*read_std)->completion)
	{
		update_index(read_std, -1);
		if ((*read_std)->comp->tab_->index == ((*read_std)->comp->tab_->element - 1) || 
					!(((*read_std)->comp->tab_->index + 1) % (*read_std)->comp->tab_->elem_page))
		{
			reprint_cmd(read_std, 1);
			print_tab_(read_std);
			reprint_cmd(read_std, 0);
		}
		else
			back_completion(read_std);
		(*read_std)->completion++;
	}
	else
		if ((*read_std)->cmd->prev)
			if ((*read_std)->history ||
					(!(*read_std)->history && (*read_std)->cmd->prev->c != 10))
				(*read_std)->cmd = (*read_std)->cmd->prev;
	return (1);
}

int			arrow_right(t_read **read_std)
{
	if ((*read_std)->completion)
	{
		update_index(read_std, 1);
		if (!(((*read_std)->comp->tab_->index) % (*read_std)->comp->tab_->elem_page))
		{
			reprint_cmd(read_std, 1);
			print_tab_(read_std);
			reprint_cmd(read_std, 0);
		}
		else 
		{
			continue_completion(read_std);
		}
		(*read_std)->completion++;
	}
	else
		if ((*read_std)->cmd->next)
			(*read_std)->cmd = (*read_std)->cmd->next;

	return (1);
}

int			arrow_up(t_read **read_std)
{
	if ((*read_std)->completion)
	{
		SAVE;
		MV_BOT;
		P_RST_FD(init_fd());
		to_up(read_std, 0, 0);
		(*read_std)->completion++;
		RESTORE;
	}
	else
		;
	return (1);
}

int			arrow_down(t_read **read_std)
{
	if ((*read_std)->completion)
	{
		SAVE;
		MV_BOT;
		P_RST_FD(init_fd());
		to_down(read_std);
		(*read_std)->completion++;
		RESTORE;
	}
	else
		;
	return (1);
}
