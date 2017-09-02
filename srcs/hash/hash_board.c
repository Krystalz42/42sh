/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_board.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/02 16:01:59 by aroulin           #+#    #+#             */
/*   Updated: 2017/09/02 16:02:02 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

t_hash		*hash_board(void)
{
	static t_hash	h_board[LEN_HASH];

	return (h_board);
}

char		*search_path(char *binary)
{
	unsigned int		index;
	t_hash				*hash_tab;

	index = hash_value(binary);
	hash_tab = hash_board();
	if (hash_tab[index].path)
		return (hash_tab[index].path);
	return (NULL);
}

void		add_hash(char *bin, char *path)
{
	unsigned int		index;
	t_hash				*hash_tab;

	index = hash_value(bin);
	hash_tab = hash_board();
	hash_tab[index].path = path;
	hash_tab[index].binary = bin;
}
