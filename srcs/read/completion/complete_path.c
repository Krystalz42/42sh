/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complete_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/13 04:23:45 by aroulin           #+#    #+#             */
/*   Updated: 2017/08/16 18:34:24 by aroulin          ###   ########.fr       */
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
	tab_->nbr = (tgetnum("co") / tab_->len);
	tab_->li = tgetnum("li");
}

void		complete_path(t_read **read_std, char *str)
{
	t_cmd		*tmp;

	if (!((*read_std)->comp = (t_completion *)ft_memalloc(sizeof(t_completion))))
		return ;
	if (!((*read_std)->comp->tab_ = (t_tab *)ft_memalloc(sizeof(t_tab))))
		return ;
	(*read_std)->comp->tab_->file = NULL;
	create_comp(read_std, str);
	(*read_std)->completion = 2;
	init_tab_((*read_std)->comp->tab_);
	print_tab_((*read_std)->comp->tab_);
	tmp = first_cmd((*read_std)->cmd, (*read_std)->history);
	restore_cursor_((*read_std)->cur);
	print_list(1, tmp, (*read_std)->cmd);
}
