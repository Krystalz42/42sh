/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complete_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/13 04:23:45 by aroulin           #+#    #+#             */
/*   Updated: 2017/08/22 15:49:41 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

int			init_tab_(t_tab *tab_, int li)
{
	int		len;
	t_file	*tmp;

	len = 0;
	tmp = tab_->file;
	while (tmp)
	{
		len = (ft_strlen(tmp->name) > (size_t)len) ? ft_strlen(tmp->name) : len;
		tmp = tmp->next;
	}
	tab_->len = len + 5;
	if (!(tab_->co = (tgetnum("co") / tab_->len) * tab_->len))
		return (0);
	tab_->nbr = (tgetnum("co") / tab_->len);
	tab_->li = tgetnum("li");
	tab_->elem_page = (tab_->li - li) * tab_->nbr;
	NBR_FD(tab_->elem_page, fdb);
	CHAR_FD(10,fdb);

	return (1);
}
void		rst(t_read **read_std, int to)
{
		restore_cursor_((*read_std)->cur);
			print_list(to, first_cmd((*read_std)->cmd, (*read_std)->history),
								(*read_std)->cmd, (*read_std));
}

int			reprint_cmd(t_read **read_std, int t)
{
	if (t)
	{
		(*read_std)->cur.save = (*read_std)->cur.line;
		rst(read_std, 0);
		insert_one_line();
		CLEAR_FROM_CUR;
	}
	else
	{
		MV_TOP;
		rst(read_std, 1);
	}
	return (1);
}

void		complete_path(t_read **read_std, t_path f)
{
	if (!((*read_std)->comp = (t_completion *)ft_memalloc(sizeof(t_completion))))
		return ;
	if (!((*read_std)->comp->tab_ = (t_tab *)ft_memalloc(sizeof(t_tab))))
		return ;
	(*read_std)->comp->from = ft_strdup(f.to_comp);
	(*read_std)->comp->tab_->file = NULL;
	create_comp(read_std, f);
	if (!(init_tab_((*read_std)->comp->tab_, (*read_std)->cur.line)))
	{
		(*read_std)->completion--;
		return ;
	}
	reprint_cmd(read_std, 1) && print_tab_(read_std) && reprint_cmd(read_std, 0);
}
