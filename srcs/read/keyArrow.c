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

int			keyArrowLeft(t_read **readStd)
{
	if ((*readStd)->completion)
	{
		updateIndex(readStd, -1);
		if ((*readStd)->comp->tab_->index == ((*readStd)->comp->tab_->element - 1) ||
					!(((*readStd)->comp->tab_->index + 1) % (*readStd)->comp->tab_->elem_page))
		{
			reprintCmd(readStd, 1);
			printTab(readStd);
			reprintCmd(readStd, 0);
		}
		else
			backCompletion(readStd);
		(*readStd)->completion++;
	}
	else
		if ((*readStd)->cmd->prev)
			if ((*readStd)->history ||
					(!(*readStd)->history && (*readStd)->cmd->prev->c != 10))
				(*readStd)->cmd = (*readStd)->cmd->prev;
	return (1);
}

int			keyArrowRight(t_read **readStd)
{
	if ((*readStd)->completion)
	{
		updateIndex(readStd, 1);
		if (!(((*readStd)->comp->tab_->index) % (*readStd)->comp->tab_->elem_page))
		{
			reprintCmd(readStd, 1);
			printTab(readStd);
			reprintCmd(readStd, 0);
		}
		else 
		{
			continue_completion(readStd);
		}
		(*readStd)->completion++;
	}
	else
		if ((*readStd)->cmd->next)
			(*readStd)->cmd = (*readStd)->cmd->next;

	return (1);
}

int			keyArrowUp(t_read **readStd)
{
	if ((*readStd)->completion)
	{
		toUp(readStd);
		(*readStd)->completion++;
	}
	else
		previousHistory(readStd);
	return (1);
}

int			keyArrowDown(t_read **readStd)
{
	if ((*readStd)->completion)
	{
		toDown(readStd);
		(*readStd)->completion++;
	}
	else
		nextHistory(readStd);
	return (1);
}
