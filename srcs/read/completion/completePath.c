/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   completePath.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/13 04:23:45 by aroulin           #+#    #+#             */
/*   Updated: 2017/08/30 21:03:07 by aroulin          ###   ########.fr       */
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
	if (!tab_->element || !(tab_->co = (tgetnum("co") / tab_->len) * tab_->len))
		return (0);
	tab_->nbr = (tgetnum("co") / tab_->len);
	tab_->li = tgetnum("li");
	tab_->elem_page = (tab_->li - li) * tab_->nbr;
	return (1);
}
void		rst(t_read **readStd, int to)
{
		restoreCursor((*readStd)->cur);
			printList(to, firstCmd((*readStd)->cmd, (*readStd)->history),
								(*readStd)->cmd, (*readStd));
}

int			reprintCmd(t_read **readStd, int t)
{
	if (t)
	{
		(*readStd)->cur.save = (*readStd)->cur.line;
		rst(readStd, 0);
		insertOneLine();
		CLEAR_FROM_CUR;
	}
	else
	{
		MV_TOP;
		rst(readStd, 1);
	}
	return (1);
}

void		completePath(t_read **readStd, t_path f)
{
	if (!((*readStd)->comp = (t_completion *)ft_memalloc(sizeof(t_completion))))
		return ;
	if (!((*readStd)->comp->tab_ = (t_tab *)ft_memalloc(sizeof(t_tab))))
		return ;
	(*readStd)->comp->from = ft_strdup(f.to_comp);
	(*readStd)->comp->tab_->file = NULL;
	createComp(readStd, f);
	((*readStd)->comp->tab_->element) ? reprintCmd(readStd, 1) : bip();
	if (!(*readStd)->comp->tab_->element ||
		(!(init_tab_((*readStd)->comp->tab_, (*readStd)->cur.line))))
	{
		(*readStd)->completion--;
		return ;
	}
	 printTab(readStd);
	 reprintCmd(readStd, 0);
}
