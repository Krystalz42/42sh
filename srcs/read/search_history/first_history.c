/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_history.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/05 20:39:49 by aroulin           #+#    #+#             */
/*   Updated: 2017/09/05 20:39:50 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

t_hist  *first_history(void)
{
    t_hist      *first;

    if (!(first = gbl_save_history(NULL, 1)))
        return (NULL);
    while (first->next)
        first = first->next;
    return (first);
}