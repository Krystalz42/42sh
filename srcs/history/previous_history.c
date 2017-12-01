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

static t_hist	*jobs_previous_history_first(t_read **read_std, t_hist *hist)
{
	t_hist *hist_temp;

	hist_temp = hist;
	if ((*read_std)->cmd->c == '\0' && (*read_std)->cmd->prev == NULL)
	{
		(*read_std)->history = 1;
		memdel_outstanding();
		copy_cmd(read_std, hist->hist->cmd);
	}
	else
	{
		memdel_cmd(&((*read_std)->history_compare));
		(*read_std)->history_compare = copy_command((*read_std)->cmd);
		while (!list_compare((*read_std)->history_compare,
							first_cmd(hist_temp->hist->cmd, 1)))
		{
			if (hist_temp->prev == NULL && bip())
				return (hist);
			hist_temp = hist_temp->prev;
		}
		memdel_outstanding();
		change_command(read_std, hist_temp);
		(*read_std)->history = 1;
	}
	return (hist_temp);
}

static t_hist	*jobs_previous_history_other(t_read **read_std, t_hist *hist)
{
	t_hist *hist_temp;

	hist_temp = hist;
	if ((*read_std)->history_compare == NULL)
	{
		memdel_outstanding();
		memdel_cmd(&((*read_std)->cmd));
		copy_cmd(read_std, hist->hist->cmd);
		hist = hist->prev ? hist->prev : hist;
	}
	else
	{
		hist_temp = hist_temp->prev ? hist_temp->prev : hist_temp;
		while (!list_compare((*read_std)->history_compare,
							first_cmd(hist_temp->hist->cmd, 1)))
		{
			if (hist_temp->prev == NULL && bip())
				return (hist);
			hist_temp = hist_temp->prev;
		}
		memdel_outstanding();
		change_command(read_std, hist_temp);
		return (hist_temp);
	}
	return (hist);
}

void			previous_history(t_read **read_std)
{
	t_hist		*hist;

	hist = gbl_save_history(NULL, REC_STRUCT);
	if (!(*read_std)->history && hist)
		hist = jobs_previous_history_first(read_std, hist);
	else if ((*read_std)->history && hist && hist->prev)
		hist = jobs_previous_history_other(read_std, hist);
	else
		bip();
	gbl_save_history(hist, SAVE_STRUCT);
}
