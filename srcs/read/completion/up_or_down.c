/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   up_or_down.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 14:15:25 by aroulin           #+#    #+#             */
/*   Updated: 2017/08/20 17:19:00 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

int			to_up2(t_read **r, t_file *tmp, int to_p)
{
	tmp = (*r)->comp->tab_->file;
	while (tmp->index != to_p)
		tmp = tmp->next;
	(*r)->comp->tab_->index = to_p;
	print_element(tmp, 0);
	return (1);
}

void		to_up(t_read **r, int d, int to_p)
{
	t_file	*tmp;

	tmp = (*r)->comp->tab_->file;
	while (tmp)
	{
		if (tmp->index == (*r)->comp->tab_->index && print_element(tmp, 1))
		{
			P_INV_FD(init_fd());
			if ((((to_p = tmp->index - (*r)->comp->tab_->nbr) %
							(*r)->comp->tab_->element) >= 0) && to_up2(r, tmp, to_p))
				break ;
			else
			{
				while ((((*r)->comp->tab_->element - ++d) %
							(*r)->comp->tab_->nbr) != (tmp->index % (*r)->comp->tab_->nbr))
					;
				(*r)->comp->tab_->index = (*r)->comp->tab_->element - d;
				tmp = (*r)->comp->tab_->file;
				while (tmp->index != (*r)->comp->tab_->index)
					tmp = tmp->next;
				print_element(tmp, 0);
			}
		}
		tmp = tmp->next;
	}
}

int			to_down(t_read **r)
{
	t_file	*tmp;
	int		to_p;
	int d = 0;

	tmp = (*r)->comp->tab_->file;
	while (tmp)
	{
		if (tmp->index == (*r)->comp->tab_->index && print_element(tmp, 1))
		{
			P_INV_FD(init_fd());
			if ((((to_p = tmp->index + (*r)->comp->tab_->nbr) < (*r)->comp->tab_->element)) && to_up2(r, tmp, to_p))
				break ;
			else
			{
				d = tmp->index;
				tmp = (*r)->comp->tab_->file;
				while ((d % (*r)->comp->tab_->nbr) != (tmp->index % (*r)->comp->tab_->nbr))
					tmp = tmp->next;
				(*r)->comp->tab_->index =  tmp->index;
				print_element(tmp, 0);
			}
		}
		tmp = tmp->next;
	}
	return (1);
}
