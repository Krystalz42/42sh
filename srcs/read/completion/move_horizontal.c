/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_horizontal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 18:25:47 by aroulin           #+#    #+#             */
/*   Updated: 2017/10/05 16:01:10 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

void			move_completion_left(t_read **read_std)
{
	update_index(read_std, -1);
	if ((*read_std)->tab_->index == ((*read_std)->tab_->element - 1) ||
			!(((*read_std)->tab_->index + 1) % (*read_std)->tab_->elem_page))
	{
		place_cursor(read_std, 1);
		print_tab(read_std);
		place_cursor(read_std, 0);
	}
	else
		back_completion(read_std);
	(*read_std)->completion++;
}

void			move_completion_right(t_read **read_std)
{
	update_index(read_std, 1);
	if (!((*read_std)->tab_->index % (*read_std)->tab_->elem_page) )
	{
		place_cursor(read_std, 1);
		print_tab(read_std);
		place_cursor(read_std, 0);
	}
	else
		continue_completion(read_std);
	(*read_std)->completion++;
}
