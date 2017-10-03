/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   continue_completion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 22:29:39 by aroulin           #+#    #+#             */
/*   Updated: 2017/10/02 22:29:43 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

void			print_back(t_read **read_std, t_file *tmp)
{
	(*read_std)->tab_->index--;
	print_element(tmp, 0);
	tmp = tmp->next;
	P_RST_FD(2);
	print_element(tmp, 1);
}

void			back_completion(t_read **read_std)
{
	t_file	*tmp;

	tmp = (*read_std)->tab_->file;
	SAVE;
	MV_BOT;
	while (tmp)
	{
		if (tmp->index == (*read_std)->tab_->index)
		{
			print_element(tmp, 0);
			tmp = tmp->next;
			print_element(tmp, 1);
			break ;
		}
		else if (!(*read_std)->tab_->index && !tmp->next)
		{
			break ;
		}
		tmp = tmp->next;
	}
	RESTORE;
}

void			continue_completion(t_read **read_std)
{
	t_file	*tmp;

	tmp = (*read_std)->tab_->file;
	SAVE;
	MV_BOT;
	while (tmp)
	{
		if (tmp->index == (*read_std)->tab_->index)
		{
			print_element(tmp, 0);
			tmp = tmp->prev;
			print_element(tmp, 1);
			(tmp->prev) && (tmp = tmp->prev);
			break ;
		}
		tmp = tmp->next;
	}
	RESTORE;
}
