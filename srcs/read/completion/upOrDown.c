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

void		toUp(t_read **readStd)
{
	t_file	*tmp;

	tmp = (*readStd)->comp->tab_->file;
	while (tmp->index != (*readStd)->comp->tab_->index)
		tmp = tmp->next;
	updateIndex(readStd, (*readStd)->comp->tab_->nbr * -1);
	if (((*readStd)->comp->tab_->index / (*readStd)->comp->tab_->elem_page) != (*readStd)->comp->tab_->page)
	{
		reprintCmd(readStd, 1);
		printTab(readStd);
		reprintCmd(readStd, 0);
	}
	else
	{
		SAVE;
		MV_BOT;
		printElement(tmp, 1);
		tmp = (*readStd)->comp->tab_->file;
		while (tmp->index != (*readStd)->comp->tab_->index)
			tmp = tmp->next;
		printElement(tmp, 0);
		RESTORE;
	}
}

int			toDown(t_read **readStd)
{
	t_file	*tmp;

	tmp = (*readStd)->comp->tab_->file;
	while (tmp->index != (*readStd)->comp->tab_->index)
		tmp = tmp->next;
	updateIndex(readStd, (*readStd)->comp->tab_->nbr * 1);
	if (((*readStd)->comp->tab_->index / (*readStd)->comp->tab_->elem_page) != (*readStd)->comp->tab_->page)
	{
		reprintCmd(readStd, 1);
		printTab(readStd);
		reprintCmd(readStd, 0);
	}
	else
	{
		SAVE;
		MV_BOT;
		printElement(tmp, 1);
		tmp = (*readStd)->comp->tab_->file;
		while (tmp->index != (*readStd)->comp->tab_->index)
			tmp = tmp->next;
		printElement(tmp, 0);
		RESTORE;
	}
	return (1);
}
