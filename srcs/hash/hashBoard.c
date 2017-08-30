/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashBoard.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/30 17:41:36 by aroulin           #+#    #+#             */
/*   Updated: 2017/08/30 18:55:09 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

t_hash		*hashBoard(void)
{
	static t_hash	hBoard[LEN_HASH];
	
	return (hBoard);
}


char		*searchPath(char *binary)
{
	unsigned int		index;
	t_hash				*hashTab;

	index = hashValue(binary);
	hashTab = hashBoard();
	if (hashTab[index].path)
		return (hashTab[index].path);
	return (NULL);
}

void		addHash(char *bin, char *path)
{
	unsigned int		index;
	t_hash				*hashTab;

	index = hashValue(bin);
	hashTab = hashBoard();
	hashTab[index].path = path;
	hashTab[index].binary = bin;
}
