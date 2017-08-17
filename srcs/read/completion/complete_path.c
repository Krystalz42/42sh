/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complete_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/13 04:23:45 by aroulin           #+#    #+#             */
/*   Updated: 2017/08/17 22:30:40 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

void			init_tab_(t_tab *tab_)
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
	tab_->co = (tgetnum("co") / tab_->len) * tab_->len;
	tab_->nbr = (tgetnum("co") / tab_->len);
	tab_->li = tgetnum("li");
}

void		complete_path(t_read **read_std, t_path f)
{
	t_cmd		*tmp;

	if (!((*read_std)->comp = (t_completion *)ft_memalloc(sizeof(t_completion))))
		return ;
	if (!((*read_std)->comp->tab_ = (t_tab *)ft_memalloc(sizeof(t_tab))))
		return ;
	(*read_std)->comp->from = ft_strdup(f.to_comp);
	(*read_std)->comp->tab_->file = NULL;
	create_comp(read_std, f);
	init_tab_((*read_std)->comp->tab_);
	print_tab_(read_std);
	tmp = first_cmd((*read_std)->cmd, (*read_std)->history);
	restore_cursor_((*read_std)->cur);
	print_list(1, tmp, (*read_std)->cmd);
}
