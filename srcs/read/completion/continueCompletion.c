/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complete_comp.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/13 04:40:22 by aroulin           #+#    #+#             */
/*   Updated: 2017/08/23 17:07:28 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

void			print_back(t_read **readStd, t_file *tmp)
{
	(*readStd)->comp->tab_->index--;
	printElement(tmp, 0);
	tmp = tmp->next;
	P_RST_FD(initFd());
	printElement(tmp, 1);
}

void			backCompletion(t_read **readStd)
{
	t_file	*tmp;

	tmp = (*readStd)->comp->tab_->file;
	SAVE;
	MV_BOT;
	while (tmp)
	{
		if (tmp->index == (*readStd)->comp->tab_->index)
		{
			printElement(tmp, 0);
			tmp = tmp->next;
			printElement(tmp, 1);
			break ;
		}
		else if (!(*readStd)->comp->tab_->index && !tmp->next)
		{
			break ;
		}
		tmp = tmp->next;
	}
	RESTORE;
}

void			continue_completion(t_read **readStd)
{
	t_file	*tmp;

	tmp = (*readStd)->comp->tab_->file;
	SAVE;
	MV_BOT;
	while (tmp)
	{
		if (tmp->index == (*readStd)->comp->tab_->index)
		{
			printElement(tmp, 0);
			tmp = tmp->prev;
			printElement(tmp, 1);
			(tmp->prev) && (tmp = tmp->prev);
			break;
		}
		tmp = tmp->next;
	}
	RESTORE;
}
