/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_board.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 19:50:39 by aroulin           #+#    #+#             */
/*   Updated: 2017/10/30 17:49:16 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

t_hash		**hash_board(void)
{
	static t_hash	*h_board[USHRT_MAX];

	return (h_board);
}

char		*search_path(char *binary)
{
	unsigned int		index;
	t_hash				**hash_tab;
	t_hash				*tmp;

	index = hash_value(binary);
	hash_tab = hash_board();
	if ((tmp = hash_tab[index]))
		while (tmp)
		{
			if (ft_strequ(binary, tmp->binary))
			{
				tmp->times += 1;
				return (ft_strdup(tmp->path));
			}
			tmp = tmp->next;
		}
	return (NULL);
}

static t_hash		*create_hash(char *bin, char *path, size_t times)
{
	t_hash	*hash;

	hash = (t_hash *)ft_memalloc(sizeof(t_hash));
	hash->path = ft_strdup(path);
	hash->binary = ft_strdup(bin);
	hash->times = times;
	hash->next = NULL;
	return (hash);
}

void		add_hash(char *bin, char *path, size_t times)
{
	unsigned int		index;
	t_hash				**hash_tab;
	t_hash				*tmp;

	hash_tab = hash_board();
	index = hash_value(bin);
	if ((tmp = hash_tab[index]))
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = create_hash(bin, path, times);
	}
	else
	{
		hash_tab[index] = create_hash(bin, path, times);
		inventory_hash(index);
	}
}
