/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/13 06:58:08 by aroulin           #+#    #+#             */
/*   Updated: 2017/08/16 21:32:38 by aroulin          ###   ########.fr       */
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

int			print_element(t_file *file)
{
	my_togoto(file->ms.y, file->ms.x);
	STR(file->name);
	my_tobackto(file->ms.y, file->ms.x + 100);
	return (1);
}

int			print_tab_(t_tab *tab_)
{
	t_file *tmp;

	tmp = tab_->file;
	insert_one_line();
	while (tmp)
	{
		(tmp->index == tab_->index) ? P_INV_FD(init_fd()) : P_RST_FD(init_fd());
		tmp->ms.y = ((tmp->index / tab_->nbr));
		tmp->ms.x= ((tmp->index % tab_->nbr) * tab_->len % tab_->co);
		tmp->ms.x2 = (tmp->index + 1) * tab_->len;
		print_element(tmp);
		tmp = tmp->next;
	}
	MV_TOP;
	return (1);
}
