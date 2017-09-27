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

	hist = gbl_save_history(NULL, 1);
	if (!(*read_std)->history && hist)
	{
		memdel_outstanding();
		copy_cmd(read_std, hist->hist->cmd);
	}
	else if ((*read_std)->history && hist && hist->prev)
	{
		memdel_outstanding();
		hist = hist->prev;
		memdel_cmd(&((*read_std)->cmd));
		copy_cmd(read_std, hist->hist->cmd);
	}
	else
		bip();
	(*read_std)->history = 1;
	gbl_save_history(hist, 1);
}
