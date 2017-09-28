/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_are_history.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/05 18:31:36 by aroulin           #+#    #+#             */
/*   Updated: 2017/09/05 18:31:37 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

void        compare_history(t_read **read_std)
{
    t_hist       *hist;
    t_cmd       *little;

    hist = first_history();
    little = first_cmd((*read_std)->hist_search->cmd, 1);
    while (hist && !list_compare(little, first_cmd(hist->hist->cmd, 1)))
        hist = hist->prev;
    if (hist)
    {
	    memdel_outstanding();
	    (*read_std)->history_search = 0;
	    if ((*read_std)->history)
		    memdel_cmd(&((*read_std)->cmd));
	    else
		    (*read_std)->history = 1;
	    copy_cmd(read_std, hist->hist->cmd);
	    (*read_std)->history_search = 1;
    }
    last_resultat((hist) || !little->c ? 0 : 1);
}