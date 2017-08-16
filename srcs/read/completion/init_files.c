/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/13 05:25:06 by aroulin           #+#    #+#             */
/*   Updated: 2017/08/13 06:51:03 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

t_file		*init_file_(char *name, unsigned char type, int index)
{
	t_file		*element;

	if (!(element = (t_file *)ft_memalloc(sizeof(t_file))))
		return (NULL);
	element->name = ft_strdup(name);
	element->type = type;
	element->index = index;
	element->select = 0;
	element->next = NULL;
	return (element);
}

void		init_files(t_file **file, char *name, unsigned char type, int index)
{
	t_file		*tmp;

	if (*file)
	{
		tmp = (*file);
		while (tmp->next)
			tmp = tmp->next;
		if (!(tmp->next = init_file_(name, type, index)))
			return ;
	}
	else
		if (!((*file) = init_file_(name, type, index)))
			return ;
}
