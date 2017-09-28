/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_history.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 18:33:19 by aroulin           #+#    #+#             */
/*   Updated: 2017/08/31 18:33:21 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

int            key_search_history(t_read **read_std, unsigned long buff)
{
    (void) buff;
    if ((*read_std)->completion)
    {
        memdel_completion(&((*read_std)->tab_));
	    (*read_std)->completion = 0;
    }
    if ((*read_std)->history_search)
        (*read_std)->history_search++;
    else
    {
        init_research(read_std);
        (*read_std)->history_search = 2;
    }
    return (1);
}