/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_hash.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 14:34:16 by aroulin           #+#    #+#             */
/*   Updated: 2017/10/02 22:18:28 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

uint8_t		hash_reset(void)
{
	int				index;
	unsigned int	*table;
	t_hash			**table_hash;
	t_hash			*tmp;
	t_hash			*to_kill;

	index = 0;
	table = index_of_hash();
	table_hash = hash_board();
	while (table[++index])
	{
		tmp = table_hash[table[index]];
		while (tmp)
		{
			to_kill = tmp;
			ft_memdel((void **)&(tmp->binary));
			ft_memdel((void **)&(tmp->path));
			tmp = tmp->next;
			ft_memdel((void **)&to_kill);
			table_hash[table[index]] = NULL;
			table[index] = 0;
		}
		table_hash[table[index]] = NULL;
		index++;
	}
	return (0);
}

uint8_t		hash_print(int fd)
{
	int				index;
	unsigned int	*table;
	t_hash			**table_hash;
	t_hash			*tmp;

	index = -1;
	table = index_of_hash();
	table_hash = hash_board();
	while (table[++index])
	{
		tmp = table_hash[table[index]];
		while (tmp)
		{
			NBR_FD(tmp->times, fd);
			CHAR_FD(':', fd);
			STR_FD(tmp->binary, fd);
			CHAR_FD('=', fd);
			STR_FD(tmp->path, fd);
			CHAR_FD('\n', fd);
			tmp = tmp->next;
		}
	}
	return (0);
}
