/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_index.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 18:27:56 by aroulin           #+#    #+#             */
/*   Updated: 2017/08/22 23:47:48 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

void		update_index(t_read **read_std, int i)
{
	if ((i == 1) && ((*read_std)->comp->tab_->index + 1) ==
			(*read_std)->comp->tab_->element)
		(*read_std)->comp->tab_->index = 0;
	else if ((i == -1) && !((*read_std)->comp->tab_->index))
	{
		(*read_std)->comp->tab_->index = ((*read_std)->comp->tab_->element - 1);
	}
	else
		(*read_std)->comp->tab_->index += i;

}
