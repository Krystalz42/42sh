/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memdel_completion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 18:38:00 by aroulin           #+#    #+#             */
/*   Updated: 2017/09/23 20:02:51 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

void		memdel_files(t_file *file)
{
	free(file->name);
	free(file);
}

int			memdel_completion(t_tab **tab_)
{
	t_file	*tmp;

	if (*tab_)
	{
		if ((*tab_)->from)
			ft_strdel(&((*tab_)->from));
		while ((*tab_)->file)
		{
			tmp = (*tab_)->file;
			(*tab_)->file = (*tab_)->file->next;
			memdel_files(tmp);
		}
		ft_memdel((void **)&((*tab_)));
		ft_memdel((void **)tab_);
	}
	return (1);
}
