/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   updateIndex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 18:27:56 by aroulin           #+#    #+#             */
/*   Updated: 2017/08/23 17:02:03 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

void		updateIndex(t_read **readStd, int i)
{
	(*readStd)->comp->tab_->index += i;
	if ((*readStd)->comp->tab_->index >= (*readStd)->comp->tab_->element)
		(*readStd)->comp->tab_->index = 0 + ((*readStd)->comp->tab_->index
				% (*readStd)->comp->tab_->element);
	else if ((*readStd)->comp->tab_->index < 0)
		(*readStd)->comp->tab_->index = (*readStd)->comp->tab_->element +
			((*readStd)->comp->tab_->index);

}
