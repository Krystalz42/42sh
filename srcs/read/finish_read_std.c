/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish_read_std.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 16:43:48 by aroulin           #+#    #+#             */
/*   Updated: 2017/08/30 19:10:23 by aroulin          ###   ########.fr       */
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
	reset_history();
	if ((*read_std)->history)
		memdel_cmd(&tmp);
	if ((*read_std)->finish == 2 ||
			(!(*read_std)->cmd->c && !(*read_std)->cmd->prev))
		memdel_read(read_std);
	else 
	{
		(*read_std)->finish = 0;
		make_list_hist((*read_std));
	}
}
