/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makeListHist.c     	                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 19:56:49 by aroulin           #+#    #+#             */
/*   Updated: 2017/08/24 16:52:45 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

t_hist		*create_hist(t_read *readStd)
{
	t_hist	*lst;

	if (!readStd)
		return (NULL);
	if (!(lst = (t_hist *)ft_memalloc(sizeof(t_hist))))
		return (NULL);
	lst->hist = readStd;
	lst->next = NULL;
	lst->prev = NULL;
	return (lst);
}

void		makeListHist(t_read *readStd)
{
	t_hist	*lst;

	lst = gblSaveHistory(NULL);
	if (lst)
	{
		while (lst->next)
			lst = lst->next;
		lst->next = create_hist(readStd);
		lst->next->prev = lst;
		gblSaveHistory(lst->next);
	}
	else
		gblSaveHistory(create_hist(readStd));
}
