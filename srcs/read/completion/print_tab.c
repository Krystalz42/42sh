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

int			init_page(t_read **read_std, t_file **tmp)
{
	(*read_std)->tab_->page = ((*read_std)->tab_->index) /
		((*read_std)->tab_->elem_page);
	while ((*tmp)->next && (*tmp)->index != (*read_std)->tab_->page * (*read_std)->tab_->elem_page)
		(*tmp) = (*tmp)->next;
	return ((*read_std)->tab_->elem_page * ((*read_std)->tab_->page + 1));
}


int			print_element(t_file *file, int color)
{
	if (!color)
	log_info("Ligne [%d] && Column [%d]",file->ms.y, file->ms.x);
	if (file)
	{

		(!color) ? P_INV_FD(2) : NULL;
		color_completion(file->type, color);
		my_togo(file->ms.y, file->ms.x);
		STR_FD(file->name, 2);
		STR_FD(RST, 2);
		add_little_char(file->type);
		my_tobackto(file->ms.y, file->ms.x + 100);
		P_RST_FD(2);
	}
	return (1);
}



int			print_tab(t_read **read_std)
{
	t_file		*tmp;
	int			stop;

	tmp = (*read_std)->tab_->file;
	if ((*read_std)->tab_->element == 1)
		insert_completion(read_std, (*read_std)->tab_->file);
	else if ((stop = init_page(read_std, &tmp)))
	{
		while (tmp && tmp->index < stop)
		{
			tmp->ms.y = (((tmp->index % (*read_std)->tab_->elem_page)
						/ (*read_std)->tab_->nbr));
			tmp->ms.x = (((tmp->index % (*read_std)->tab_->elem_page)
				% (*read_std)->tab_->nbr) * (*read_std)->tab_->len
					% (*read_std)->tab_->co);
			(tmp->index == (*read_std)->tab_->index)
				? print_element(tmp, 0) : print_element(tmp, 1);
			tmp->ms.y += ((*read_std)->cur.line - (*read_std)->cur.save);
			log_info("Completion initialisation X [%d] && Y [%d]", tmp->ms.x,tmp->ms.y);
			tmp = tmp->next;
		}
	}
	return (1);
}
