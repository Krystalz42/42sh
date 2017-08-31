/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_index.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 18:27:56 by aroulin           #+#    #+#             */
/*   Updated: 2017/08/31 21:20:13 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

void		update_index(t_read **read_std, int i)
{
	(*read_std)->comp->tab_->index += i;
	if ((*read_std)->comp->tab_->index >= (*read_std)->comp->tab_->element)
		(*read_std)->comp->tab_->index = 0 + ((*read_std)->comp->tab_->index
				% (*read_std)->comp->tab_->element);
	else if ((*read_std)->comp->tab_->index < 0)
		(*read_std)->comp->tab_->index = (*read_std)->comp->tab_->element +
			((*read_std)->comp->tab_->index);

}
