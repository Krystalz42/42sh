/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   up_or_down.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 14:15:25 by aroulin           #+#    #+#             */
/*   Updated: 2017/11/20 16:02:56 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

static inline void		change_page(t_read **read_std)
{
	place_cursor(read_std, 1);
	print_tab(read_std);
	place_cursor(read_std, 0);
}

static inline void		change_element(t_read **read_std, t_file *tmp)
{
	tputs(tgetstr("sc", 0), STDIN_FILENO, &my_put);
	tputs(tgetstr(MV_BOT, 0), STDIN_FILENO, &my_put);
	print_element(tmp, 1);
	tmp = (*read_std)->tab_->file;
	while (tmp && tmp->index != (*read_std)->tab_->index)
		tmp = tmp->next;
	print_element(tmp, 0);
	tputs(tgetstr(RESTORE, 0), STDIN_FILENO, &my_put);
}

void					move_vertical(t_read **read_std, int pos)
{
	t_file	*tmp;

	if ((*read_std)->tab_ && (*read_std)->tab_->file)
	{
		tmp = (*read_std)->tab_->file;
		while (tmp && tmp->index != (*read_std)->tab_->index)
			tmp = tmp->next;
		update_index(read_std, (*read_std)->tab_->nbr * pos);
		dprintf(fd_log, "To %d\n", (*read_std)->tab_->index);
		if (((*read_std)->tab_->index / (*read_std)->tab_->elem_page)\
			!= (*read_std)->tab_->page)
			change_page(read_std);
		else
			change_element(read_std, tmp);
	}
}
