/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_board.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/30 17:41:36 by aroulin           #+#    #+#             */
/*   Updated: 2017/08/30 18:55:09 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

t_hash		*hash_board(void)
{
	static t_hash	hBoard[LEN_HASH];
	
	return (hBoard);
}


char		*search_path(char *binary)
{
	unsigned int		index;
	t_hash				*hashTab;

	index = hash_value(binary);
	hashTab = hash_board();
	if (hashTab[index].path)
		return (hashTab[index].path);
	return (NULL);
}

void		add_hash(char *bin, char *path)
{
	unsigned int		index;
	t_hash				*hashTab;

	index = hash_value(bin);
	hashTab = hash_board();
	hashTab[index].path = path;
	hashTab[index].binary = bin;
}
