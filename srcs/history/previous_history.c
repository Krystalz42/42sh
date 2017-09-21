/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   previous_history.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 15:34:32 by aroulin           #+#    #+#             */
/*   Updated: 2017/08/30 19:02:13 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

void			previous_history(t_read **read_std)
{
	t_hist		*hist;

	if (!(hist = gbl_save_history(NULL, 1)) && bip())
		return ;
	NBR_FD((*read_std)->history, fdb);
	if ((*read_std)->history)
	{
		(!hist->prev) && bip();
		(hist->prev) && (hist = hist->prev);
		memdel_cmd(&((*read_std)->cmd));
		copy_cmd(read_std, hist->hist->cmd);
	}
	else
		copy_cmd(read_std, hist->hist->cmd);
	(*read_std)->history = 1;
	gbl_save_history(hist, 1);
}
