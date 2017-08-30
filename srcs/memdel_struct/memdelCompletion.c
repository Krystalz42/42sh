/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memdelCompletion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 18:38:00 by aroulin           #+#    #+#             */
/*   Updated: 2017/08/17 21:24:16 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

void		memdel_files(t_file *file)
{
	free(file->name);
	free(file);
}

int			memdelCompletion(t_completion **comp)
{
	t_file	*tmp;
	if (*comp)
	{
		if ((*comp)->from)
			ft_strdel(&((*comp)->from));
		if ((*comp)->tab_)
		{
			while ((*comp)->tab_->file)
			{
				tmp = (*comp)->tab_->file;
				(*comp)->tab_->file = (*comp)->tab_->file->next;
				memdel_files(tmp);
			}
			ft_memdel((void **)&((*comp)->tab_));
		}
		ft_memdel((void **)comp);
	}
		(*comp) = NULL;
	return (1);
}
