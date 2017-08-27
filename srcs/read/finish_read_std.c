/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish_read_std.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 16:43:48 by aroulin           #+#    #+#             */
/*   Updated: 2017/08/27 17:52:06 by aroulin          ###   ########.fr       */
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

void		finish_read_std(t_read **read_std)
{
	t_cmd		*tmp;

	tmp = first_cmd(gbl_save_read(NULL), 1);
	(*read_std)->finish = 0;
	reset_history();
	if ((*read_std)->history)
		memdel_cmd(&tmp);
}
