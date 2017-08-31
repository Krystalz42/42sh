/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_list_hist.c     	                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 19:56:49 by aroulin           #+#    #+#             */
/*   Updated: 2017/08/24 16:52:45 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

t_hist		*create_hist(t_read *read_std)
{
	t_hist	*lst;

	if (!read_std)
		return (NULL);
	if (!(lst = (t_hist *)ft_memalloc(sizeof(t_hist))))
		return (NULL);
	lst->hist = read_std;
	lst->next = NULL;
	lst->prev = NULL;
	return (lst);
}

void		make_list_hist(t_read *read_std)
{
	t_hist	*lst;

	lst = gbl_save_history(NULL);
	if (lst)
	{
		while (lst->next)
			lst = lst->next;
		lst->next = create_hist(read_std);
		lst->next->prev = lst;
		gbl_save_history(lst->next);
	}
	else
		gbl_save_history(create_hist(read_std));
}
