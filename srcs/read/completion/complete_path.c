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
	(*read_std)->cur = prompt(PRINT);
	print_list(to, first_cmd((*read_std)->cmd, (*read_std)->history),
			(*read_std)->cmd, &((*read_std)->cur));
}

int			place_cursor(t_read **read_std, int t)
{
	int			save;

	if (t)
	{
		save = (*read_std)->cur.line;
		reset(read_std, 0);
		(*read_std)->cur.save = save;
		insert_one_line();
		tputs(tgetstr(CLEAR_FROM_CUR, 0), STDIN_FILENO, &my_put);
	}
	else
	{
		tputs(tgetstr(MV_TOP, 0), STDIN_FILENO, &my_put);
		reset(read_std, 1);
	}
	return (1);
}

void		complete_path(t_read **read_std, t_path f)
{
	if (((*read_std)->tab_ = (t_tab *)ft_memalloc(sizeof(t_tab))) == NULL)
		return ;
	(*read_std)->tab_->from = ft_strdup(f.to_comp);
	create_comp(read_std, f);
	if (!(*read_std)->tab_->element ||
		(!(init_tab_((*read_std)->tab_, (*read_std)->cur.line))))
	{
		(*read_std)->completion = 0;
		return ;
	}
	((*read_std)->tab_->element) && place_cursor(read_std, 1);
	print_tab(read_std);
	place_cursor(read_std, 0);
}
