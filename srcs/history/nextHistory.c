/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nextHistory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 16:30:08 by aroulin           #+#    #+#             */
/*   Updated: 2017/08/30 19:01:46 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

void			nextHistory(t_read **readStd)
{
	t_hist		*hist;

	if (!(hist = gblSaveHistory(NULL)))
		return ;
	if (hist->next)
	{
		hist = hist->next;
		memdelCmd(&((*readStd)->cmd));
		copyCmd(readStd, hist->hist->cmd);
		(*readStd)->history = 1;
	}
	else if ((*readStd)->history)
	{
		(*readStd)->history = 0;
		memdelCmd(&((*readStd)->cmd));
		(*readStd)->cmd = gblSaveRead(NULL);
		(*readStd)->history = 0;
	}
	else
		bip();
	gblSaveHistory(hist);
}
