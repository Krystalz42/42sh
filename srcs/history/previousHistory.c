/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   previousHistory.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 15:34:32 by aroulin           #+#    #+#             */
/*   Updated: 2017/08/30 19:02:13 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

void			previousHistory(t_read **readStd)
{
	t_hist		*hist;

	if (!(hist = gblSaveHistory(NULL)))
		return ;
	if ((*readStd)->history)
	{
		(!hist->prev) && bip();
		(hist->prev) && (hist = hist->prev);
		memdelCmd(&((*readStd)->cmd));
		copyCmd(readStd, hist->hist->cmd);
	}
	else
	{
		(*readStd)->history = 1;
		copyCmd(readStd, hist->hist->cmd);
	}
	(*readStd)->history = 1;
	gblSaveHistory(hist);
}
