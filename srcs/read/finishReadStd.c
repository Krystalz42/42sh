/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finishReadStd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 16:43:48 by aroulin           #+#    #+#             */
/*   Updated: 2017/08/30 19:18:26 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

void		reset_history(void)
{
	t_hist	*tmp;

	if (!(tmp = gblSaveHistory(NULL)))
		return ;
	while (tmp->next)
		tmp = tmp->next;
	gblSaveHistory(tmp);
}

void		finishReadStd(t_read **readStd)
{
	t_cmd		*tmp;

	tmp = firstCmd(gblSaveRead(NULL), 1);
	reset_history();
	if ((*readStd)->history)
		memdelCmd(&tmp);
	if ((*readStd)->finish == 2 ||
			(!(*readStd)->cmd->c && !(*readStd)->cmd->prev))
		memdelRead(readStd);
	else 
	{
		(*readStd)->finish = 0;
		makeListHist((*readStd));
	}
}
