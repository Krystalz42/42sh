/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_hash.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 17:10:53 by aroulin           #+#    #+#             */
/*   Updated: 2017/10/02 22:16:48 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

unsigned int		*index_of_hash(void)
{
	static unsigned int			table[2000];

	return (table);
}

void				inventory_hash(unsigned int new_index)
{
	unsigned int	index;
	unsigned int	*table;

	index = 0;
	table = index_of_hash();
	while (index < 2000)
		if (table[index])
			index++;
		else
		{
			table[index] = new_index;
			break ;
		}
}
