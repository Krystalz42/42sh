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

int			key_arrow_left(t_read **read_std)
{
	if ((*read_std)->completion)
	{
		update_index(read_std, -1);
		if ((*read_std)->comp->tab_->index == ((*read_std)->comp->tab_->element - 1) ||
					!(((*read_std)->comp->tab_->index + 1) % (*read_std)->comp->tab_->elem_page))
		{
			place_cursor(read_std, 1);
			print_tab(read_std);
			place_cursor(read_std, 0);
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

int			key_arrow_right(t_read **read_std)
{
	if ((*read_std)->completion)
	{
		update_index(read_std, 1);
		if (!(((*read_std)->comp->tab_->index) % (*read_std)->comp->tab_->elem_page))
		{
			place_cursor(read_std, 1);
			print_tab(read_std);
			place_cursor(read_std, 0);
		}
		else
			continue_completion(read_std);
		(*read_std)->completion++;
	}
	else
		if ((*read_std)->cmd->next)
			(*read_std)->cmd = (*read_std)->cmd->next;
	return (1);
}

int			key_arrow_up(t_read **read_std)
{
	if ((*read_std)->completion)
	{
		to_up(read_std);
		(*read_std)->completion++;
	}
	else
		previous_history(read_std);
	return (1);
}

int			key_arrow_down(t_read **read_std)
{
	if ((*read_std)->completion)
	{
		to_down(read_std);
		(*read_std)->completion++;
	}
	else
		next_history(read_std);
	return (1);
}
