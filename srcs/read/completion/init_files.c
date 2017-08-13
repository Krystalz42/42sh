/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/13 05:25:06 by aroulin           #+#    #+#             */
/*   Updated: 2017/08/13 05:25:12 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

void		init_files(t_file **file, char *name, unsigned char type)
{
	t_file		*element;

	if (*file)
	{
		STR("EX\n");
		element = (*file);
		while (element->next)
			element = element->next;
		if (!(element->next = (t_file *)ft_memalloc(sizeof(t_file))))
			return ;
		element->next->name = ft_strdup(name);
		element->next->type = type;
		element->next->select = 0;
		element->next->next = NULL;
	}
	else
	{
		STR("EMP\n");
		if (!((*file) = (t_file *)ft_memalloc(sizeof(t_file))))
			return ;
		(*file)->name = ft_strdup(name);
		(*file)->type = type;
		(*file)->select = 1;
		(*file)->next = NULL;
	}
}
