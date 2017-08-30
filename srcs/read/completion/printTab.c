/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/13 06:58:08 by aroulin           #+#    #+#             */
/*   Updated: 2017/08/30 20:03:55 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

int			init_page(t_read **readStd, t_file **tmp)
{
	(*readStd)->comp->tab_->page = ((*readStd)->comp->tab_->index) /
		((*readStd)->comp->tab_->elem_page);
	NBR_FD((*tmp)->next && (*tmp)->index,fdb);
	CHAR_FD(32, fdb);
	NBR_FD(((*readStd)->comp->tab_->elem_page),fdb);
	CHAR_FD(32, fdb);
	NBR_FD((*readStd)->comp->tab_->page ,fdb);
	CHAR_FD(32, fdb);
	NBR_FD((*readStd)->comp->tab_->page * (*readStd)->comp->tab_->elem_page, fdb);
	CHAR_FD(10, fdb);
	while ((*tmp)->next && (*tmp)->index != (*readStd)->comp->tab_->page * (*readStd)->comp->tab_->elem_page)
		(*tmp) = (*tmp)->next;
	return ((*readStd)->comp->tab_->elem_page * ((*readStd)->comp->tab_->page + 1));
}


int			printElement(t_file *file, int color)
{
	(!color) ? P_INV_FD(initFd()) : NULL;
	colorCompletion(file->type, color);
	myToGo(file->ms.y, file->ms.x);
	STR_FD(file->name, initFd());
	STR_FD(RST, initFd());
	addLittleChar(file->type);
	myToBackTo(file->ms.y, file->ms.x + 100);
	P_RST_FD(initFd());
	return (1);
}



int			printTab(t_read **readStd)
{
	t_file		*tmp;
	int			stop;

	tmp = (*readStd)->comp->tab_->file;
	if ((*readStd)->comp->tab_->element == 1)
		complete_command(readStd);
	else if ((stop = init_page(readStd, &tmp)))
	{
		while (tmp && tmp->index < stop)
		{
			tmp->ms.y = (((tmp->index % (*readStd)->comp->tab_->elem_page)
						/ (*readStd)->comp->tab_->nbr));
			tmp->ms.x = (((tmp->index % (*readStd)->comp->tab_->elem_page)
				% (*readStd)->comp->tab_->nbr) * (*readStd)->comp->tab_->len
					% (*readStd)->comp->tab_->co);
			(tmp->index == (*readStd)->comp->tab_->index)
				? printElement(tmp, 0) : printElement(tmp, 1);
			tmp->ms.y += ((*readStd)->cur.line - (*readStd)->cur.save);
			tmp = tmp->next;
		}
	}
	return (1);
}
