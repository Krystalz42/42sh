/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complete_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/13 04:23:45 by aroulin           #+#    #+#             */
/*   Updated: 2017/08/30 21:03:07 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

void		reset(t_read **read_std, int to)
{
	restore_cursor_((*read_std)->cur);
	(*read_std)->cur.co = prompt(PRINT);
	print_list(to, first_cmd((*read_std)->cmd, (*read_std)->history),
			(*read_std)->cmd, &((*read_std)->cur));
}

int			place_cursor(t_read **read_std, int t)
{
	if (t)
	{
		(*read_std)->cur.save = (*read_std)->cur.line;
		reset(read_std, 0);
		insert_one_line();
		CLEAR_FROM_CUR;
	}
	else
	{
		MV_TOP;
		reset(read_std, 1);
	}
	return (1);
}

void		complete_path(t_read **read_std, t_path f)
{
	if (!((*read_std)->tab_ = (t_tab *)ft_memalloc(sizeof(t_tab))))
		return ;
	(*read_std)->tab_->from = ft_strdup(f.to_comp);
	(*read_std)->tab_->file = NULL;
	create_comp(read_std, f);
	((*read_std)->tab_->element) ? place_cursor(read_std, 1) : bip();
	if (!(*read_std)->tab_->element ||
		(!(init_tab_((*read_std)->tab_, (*read_std)->cur.line))))
	{
		(*read_std)->completion = 0;
		return ;
	}
	print_tab(read_std);
	place_cursor(read_std, 0);
}
