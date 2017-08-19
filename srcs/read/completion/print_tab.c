/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/13 06:58:08 by aroulin           #+#    #+#             */
/*   Updated: 2017/08/19 14:19:50 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

int			my_tobackto(int li, int co)
{
	if (li >= 0)
		while (li)
		{
			MV_TOP;
			li--;
		}
	if (co >= 0)
		while (co)
		{
			MV_LEFT;
			co--;
		}

	return (1);
}

int			my_togoto(int li, int co)
{
	if (li >= 0)
		while (li)
		{
			MV_BOT;
			li--;
		}
	if (co >= 0)
		while (co)
		{
			MV_RIGHT;
			co--;
		}
	return (1);
}

int			print_element(t_file *file, int color)
{
	color_completion(file->type, color);
	my_togoto(file->ms.y, file->ms.x);
	STR_FD(file->name, init_fd());
	STR_FD(RST, init_fd());
	add_little_char(file->type);
	my_tobackto(file->ms.y, file->ms.x + 100);
	return (1);
}

int			print_tab_(t_read **read_std)
{
	t_file *tmp;

	tmp = (*read_std)->comp->tab_->file;
	if ((*read_std)->comp->tab_->element == 1)
		complete_command(read_std);
	else
	{
		insert_one_line();
		while (tmp)
		{
			(tmp->index == (*read_std)->comp->tab_->index) ? P_INV_FD(init_fd()) : P_RST_FD(init_fd());
			tmp->ms.y = ((tmp->index / (*read_std)->comp->tab_->nbr));
			tmp->ms.x= ((tmp->index % (*read_std)->comp->tab_->nbr) * (*read_std)->comp->tab_->len % (*read_std)->comp->tab_->co);
			(tmp->index == (*read_std)->comp->tab_->index) ? print_element(tmp, 0) : print_element(tmp, 1);
			tmp = tmp->next;
		}
		MV_TOP;
	}
	return (1);
}
