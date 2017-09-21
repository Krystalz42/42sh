/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_history.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 14:08:21 by aroulin           #+#    #+#             */
/*   Updated: 2017/09/21 14:08:22 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

/*
**  [-c]            Supprimme l'historique dans le 42sh
**  [-d] offset     Supprime l'index de l'historique dans le 42sh
**	[-a]            Ecrit l'historique dans le fichier PATH_HIST
** 	[-n]            ?
**  [-r]            Ecrit le contenu de PATH_HIST dans l'historique du 42sh
**  [-w]            Ecrit l'historique dans le PATH_HIST
**  [-p]            Ecrit les args sur la sortie standart
**  [-s]            Ajoute les args dans l'historique
**  [-anrw]
*/

int        b_write_history(void)
{
	t_hist  *hist;
	int     index;
	t_cmd   *tmp;

	hist = set_history_to_last();
	index = 0;
	while (hist)
	{
		NBR_FD(++index, 2);
		CHAR_FD(32, 2);
		tmp = first_cmd(hist->hist->cmd, 1);
		while (tmp->c)
		{
			CHAR_FD(tmp->c, 2);
			tmp = tmp->next;
		}
		hist = hist->next;
		CHAR_FD(10, 2);
	}
	return (index);
}

int        b_clear_history(void)
{
	t_hist  *hist;
	t_hist  *to_kill;

	reset_history();
	if (!(hist = gbl_save_history(NULL, 1)))
		return (0);
	while (hist)
	{
		memdel_read(&(hist->hist));
		to_kill = hist;
		hist = hist->prev;
		ft_memdel((void **)&to_kill);

	}
	gbl_save_history(NULL, 0);
	return (1);
}

int        b_delete_history_offset(int offset)
{
	t_hist  *hist;
	t_hist  *to_kill;
	int     i;

	i = 0;
	hist = set_history_to_last();
	while (hist)
	{
		if (++i == offset)
		{
			to_kill = hist;
			(hist->prev) && (hist->prev->next = hist->next);
			(hist->next) && (hist->next->prev = hist->prev);
			break ;
		}
		hist = hist->next;
	}

	return ((i == offset) ? 1 : 0);
}