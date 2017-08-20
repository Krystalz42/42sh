/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complete_comp.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/13 04:40:22 by aroulin           #+#    #+#             */
/*   Updated: 2017/08/20 14:14:56 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

void			print_back(t_read **read_std, t_file *tmp)
{
	(*read_std)->comp->tab_->index--;
	print_element(tmp, 0);
	tmp = tmp->next;
	P_RST_FD(init_fd());
	print_element(tmp, 1);
}

void			back_completion(t_read **read_std)
{
	t_file	*tmp;

	tmp = (*read_std)->comp->tab_->file;
	SAVE;
	MV_BOT;
	P_INV_FD(init_fd());
	while (tmp)
	{
		if (tmp->index + 1 == (*read_std)->comp->tab_->index)
		{
			print_back(read_std, tmp);
			break ;
		}
		else if (!(*read_std)->comp->tab_->index && !tmp->next)
		{
			(*read_std)->comp->tab_->index = (*read_std)->comp->tab_->element - 1;
			print_element(tmp, 0);
			P_RST_FD(init_fd());
			print_element((*read_std)->comp->tab_->file, 1);
			break ;
		}
		tmp = tmp->next;
	}
	RESTORE;
}

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
			print_element(tmp, 1);
			tmp = tmp->next;
			P_INV_FD(init_fd());
			if ((*read_std)->comp->tab_->index)
				print_element(tmp, 0);
			else
				print_element((*read_std)->comp->tab_->file, 0);
			P_RST_FD(init_fd());
			break;
		}
		tmp = tmp->next;
	}
	RESTORE;
}
