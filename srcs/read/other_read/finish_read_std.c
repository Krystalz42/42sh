/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish_read_std.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 16:43:48 by aroulin           #+#    #+#             */
/*   Updated: 2017/08/30 19:18:26 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

void		finish_read_std(t_read **read_std)
{
	t_cmd		*tmp;

	tmp = first_cmd(gbl_save_read(NULL), 1);
	reset_history();
	memdel_outstanding();
	if ((*read_std)->history)
		memdel_cmd(&tmp);
	if ((*read_std)->finish == 2 ||
			(!(*read_std)->cmd->c && !(*read_std)->cmd->prev))
		memdel_read(read_std);
	else 
	{
		(*read_std)->finish = 0;
		make_list_hist((*read_std));
        key_end_(read_std, KEY_END);
        print_struct(*read_std);
	}
}
