/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_history.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 16:30:08 by aroulin           #+#    #+#             */
/*   Updated: 2017/08/30 19:01:46 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

void			next_history(t_read **read_std)
{
	t_hist		*hist;

	if (!(hist = gbl_save_history(NULL)))
		return ;
	if (hist->next)
	{
		hist = hist->next;
		memdel_cmd(&((*read_std)->cmd));
		copy_cmd(read_std, hist->hist->cmd);
		(*read_std)->history = 1;
	}
	else if ((*read_std)->history)
	{
		(*read_std)->history = 0;
		memdel_cmd(&((*read_std)->cmd));
		(*read_std)->cmd = gbl_save_read(NULL);
		(*read_std)->history = 0;
	}
	else
		bip();
	gbl_save_history(hist);
}
