/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   up_or_down.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 14:15:25 by aroulin           #+#    #+#             */
/*   Updated: 2017/08/23 17:34:23 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

void		to_up(t_read **read_std)
{
	t_file	*tmp;

	tmp = (*read_std)->comp->tab_->file;
	while (tmp->index != (*read_std)->comp->tab_->index)
		tmp = tmp->next;
	update_index(read_std, (*read_std)->comp->tab_->nbr * -1);
	if (((*read_std)->comp->tab_->index / (*read_std)->comp->tab_->elem_page) != (*read_std)->comp->tab_->page)
	{
		reprint_cmd(read_std, 1);
		print_tab_(read_std);
		reprint_cmd(read_std, 0);
	}
	else
	{
		SAVE;
		MV_BOT;
		print_element(tmp, 1);
		tmp = (*read_std)->comp->tab_->file;
		while (tmp->index != (*read_std)->comp->tab_->index)
			tmp = tmp->next;
		print_element(tmp, 0);
		RESTORE;
	}
}

int			to_down(t_read **read_std)
{
	t_file	*tmp;

	tmp = (*read_std)->comp->tab_->file;
	while (tmp->index != (*read_std)->comp->tab_->index)
		tmp = tmp->next;
	update_index(read_std, (*read_std)->comp->tab_->nbr * 1);
	if (((*read_std)->comp->tab_->index / (*read_std)->comp->tab_->elem_page) != (*read_std)->comp->tab_->page)
	{
		reprint_cmd(read_std, 1);
		print_tab_(read_std);
		reprint_cmd(read_std, 0);
	}
	else
	{
		SAVE;
		MV_BOT;
		print_element(tmp, 1);
		tmp = (*read_std)->comp->tab_->file;
		while (tmp->index != (*read_std)->comp->tab_->index)
			tmp = tmp->next;
		print_element(tmp, 0);
		RESTORE;
	}
	return (1);
}
