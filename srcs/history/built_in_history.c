/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_history.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 14:08:21 by aroulin           #+#    #+#             */
/*   Updated: 2017/09/23 19:56:29 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

/*
**  [-c]            Supprimme l'historique dans le 42sh
**                  (b_write_history)
**  [-d] offset     Supprime l'index de l'historique dans le 42sh
**                  (b_delete_history_offset)
**	[-a]            Ecrit l'historique dans le fichier PATH_HIST
**                  (b_write_history_in_file)
** 	[-n]            ?
**  [-r]            Ecrit le contenu de PATH_HIST dans l'historique du 42sh
**                  (write_history_in_sh)
**  [-w]            Ecrit l'historique dans le PATH_HIST
**  [-p]            Ecrit les args sur la sortie standart
**  [-s]            Ajoute les args dans l'historique
*/

int			b_write_history(void)
{
	t_hist	*hist;
	int		index;
	t_cmd	*tmp;

	hist = set_history_to_last();
	index = 0;
	while (hist)
	{
		NBR(++index);
		CHAR(32);
		tmp = first_cmd(hist->hist->cmd, 1);
		while (tmp->c)
		{
			CHAR(tmp->c);
			tmp = tmp->next;
		}
		hist = hist->next;
		CHAR(10);
	}
	return (index);
}

int			b_clear_history(void)
{
	t_hist		*hist;
	t_hist		*to_kill;

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

int			b_delete_history_offset(int offset)
{
	t_hist		*hist;
	t_hist		*to_kill;
	int			i;

	i = 0;
	hist = set_history_to_last();
	while (hist)
	{
		if (++i == offset)
		{
			to_kill = hist;
			(hist->prev) && (hist->prev->next = hist->next);
			(hist->next) && (hist->next->prev = hist->prev);
			ft_memdel((void **)&to_kill);
			break ;
		}
		hist = hist->next;
	}
	return ((i == offset) ? 1 : 0);
}
