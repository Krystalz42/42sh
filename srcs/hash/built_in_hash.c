/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_hash.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 14:34:16 by aroulin           #+#    #+#             */
/*   Updated: 2017/09/23 19:47:16 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

void				hash_reset(void)
{
	t_hash			**hash_tab;
	t_table_hash	*table;
	t_table_hash	*to_kill;

	hash_tab = hash_board();
	table = gbl_save_table_hash(NULL, 0);
	while (table)
	{
		to_kill = table;
		ft_memdel((void **)&(hash_tab[table->index]->binary));
		ft_memdel((void **)&(hash_tab[table->index]->path));
		ft_memdel((void **)&(hash_tab[table->index]));
		table = table->next;
		ft_memdel((void **)&to_kill);
	}
	gbl_save_table_hash(NULL, 1);
}


void hash_print(int fd)
{
    t_table_hash	*table;
    static char		element[400];
    char			*tmp;

    table = gbl_save_table_hash(NULL, 0);
    while (table)
    {
        ft_bzero(element, 400);
        ft_strcpy(element, "[");
        tmp = ft_uitoa(table->index);
        ft_strcpy(element + ft_strlen(element), tmp);
        free(tmp);
        ft_strcpy(element + ft_strlen(element), ":");
        tmp = ft_uitoa((*table->hash)->times);
        ft_strcpy(element + ft_strlen(element), tmp);
        free(tmp);
        ft_strcpy(element + ft_strlen(element), "] ");
        ft_strcpy(element + ft_strlen(element), (*table->hash)->binary);
        ft_strcpy(element + ft_strlen(element), "=");
        ft_strcpy(element + ft_strlen(element), (*table->hash)->path);
        ft_strcpy(element + ft_strlen(element), "\n");
        table = table->next;
        STR_FD(element,fd);
    }
}
