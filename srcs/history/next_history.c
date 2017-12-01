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

static t_hist	*jobs_next_history(t_read **read_std, t_hist *hist)
{
	t_hist *hist_temp;

	hist_temp = hist;
	if ((*read_std)->history_compare == NULL)
	{
		memdel_outstanding();
		hist = hist->next;
		memdel_cmd(&((*read_std)->cmd));
		copy_cmd(read_std, hist->hist->cmd);
		(*read_std)->history = 1;
	}
	else
	{
		hist_temp = hist_temp->next ? hist_temp->next : hist_temp;
		while (!list_compare((*read_std)->history_compare,
							 first_cmd(hist_temp->hist->cmd, 1)))
		{
			if (hist_temp->next == NULL && bip())
				return (hist);
			hist_temp = hist_temp->next;
		}
		memdel_outstanding();
		change_command(read_std, hist_temp);
		return (hist_temp);
	}
	return (hist);
}

void			next_history(t_read **read_std)
{
	t_hist		*hist;

	hist = gbl_save_history(NULL, REC_STRUCT);
	if (hist && hist->next)
	{
		hist = jobs_next_history(read_std, hist);

	}
	else if ((*read_std)->history)
	{
		memdel_outstanding();
		memdel_cmd(&((*read_std)->cmd));
		(*read_std)->cmd = gbl_save_read(NULL);
		(*read_std)->history = 0;
	}
	else
		bip();
	gbl_save_history(hist, SAVE_STRUCT);
}
