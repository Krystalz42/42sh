/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   previous_history.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 15:34:32 by aroulin           #+#    #+#             */
/*   Updated: 2017/08/27 18:19:23 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

void			previous_history(t_read **read_std)
{
	t_hist		*hist;

	if (!(hist = gbl_save_history(NULL)))
		return ;
	if ((*read_std)->history)
	{
		(!hist->prev) && bip();
		(hist->prev) && (hist = hist->prev);
		memdel_cmd(&((*read_std)->cmd));
		copy_cmd(read_std, hist->hist->cmd);
	}
	else
	{
		(*read_std)->history = 1;
		copy_cmd(read_std, hist->hist->cmd);
	}

	gbl_save_history(hist);
}
