/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_hash.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 17:10:53 by aroulin           #+#    #+#             */
/*   Updated: 2017/09/23 19:54:17 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

t_table_hash		*gbl_save_table_hash(t_table_hash *hash, int flags)
{
	static t_table_hash *save;

	if (flags)
		save = NULL;
	else if (hash)
		save = hash;
	return (save);
}

t_table_hash		*init_table_hash(t_hash **hash, unsigned int index)
{
	t_table_hash *table;

	table = (t_table_hash *)ft_memalloc(sizeof(t_table_hash));
	table->hash = hash;
	table->index = index;
	table->next = NULL;
	table->prev = NULL;
	return (table);
}

void				inventory_hash(t_hash **hash, unsigned int index)
{
	t_table_hash *tmp;

	if (!(tmp = gbl_save_table_hash(NULL, 0)))
		gbl_save_table_hash(init_table_hash(hash, index), 0);
	else
	{
		tmp->prev = init_table_hash(hash, index);
		tmp->prev->next = tmp;
		gbl_save_table_hash(tmp->prev, 0);
	}
}
