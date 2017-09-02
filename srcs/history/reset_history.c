/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_history.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/02 16:35:21 by aroulin           #+#    #+#             */
/*   Updated: 2017/09/02 16:35:30 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

void		reset_history(void)
{
	t_hist	*tmp;

	if (!(tmp = gbl_save_history(NULL)))
		return ;
	while (tmp->next)
		tmp = tmp->next;
	gbl_save_history(tmp);
}
