/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complete_comp.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/13 04:40:22 by aroulin           #+#    #+#             */
/*   Updated: 2017/08/16 21:40:55 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

void			continue_completion(t_read **read_std)
{
	t_file	*tmp;

	tmp = (*read_std)->comp->tab_->file;
	SAVE;
	MV_BOT;
	while (tmp)
	{
		if (tmp->index == (*read_std)->comp->tab_->index)
		{
			if ((*read_std)->comp->tab_->index + 1 == (*read_std)->comp->tab_->element)
				(*read_std)->comp->tab_->index = 0;
			else 
				(*read_std)->comp->tab_->index++;
			print_element(tmp);
			tmp = tmp->next;
			P_INV_FD(init_fd());
			if ((*read_std)->comp->tab_->index)
				print_element(tmp);
			else
				print_element((*read_std)->comp->tab_->file);
			P_RST_FD(init_fd());
			break;
		}
		tmp = tmp->next;
	}
	RESTORE;
}
