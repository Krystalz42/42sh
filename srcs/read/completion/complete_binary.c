/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complete_binary.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/13 04:09:28 by aroulin           #+#    #+#             */
/*   Updated: 2017/08/31 18:05:04 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>
/*
void        have_to_compare(t_read **read_std)
{
    char        *cmp;
    int         i;


    if ((cmp = (char *)ft_memalloc(sizeof(char) * (len + 1))))
        return ;
    i = -1;
    while (++i < len)
    {
        cmp[i] = (*read_std)->cmd->c;
        (*read_std)->cmd = (*read_std)->cmd->next;
    }
    cmp[i] = '\0';
}
*/
void		complete_binary(t_read **read_std)
{
    t_hash	        *hash_b;
    unsigned int    index;
    int             i;

	if (!((*read_std)->comp = (t_completion *)ft_memalloc(sizeof(t_completion))))
		return ;
	if (!((*read_std)->comp->tab_ = (t_tab *)ft_memalloc(sizeof(t_tab))))
		return ;
    (*read_std)->comp->from = NULL;
	index = -1;
    i = 0;
   // have_to_compare(read_std);
    hash_b = hash_board();
    STR_FD("Salut \n", fdb);
	while (++index < LEN_HASH)
    {
        if (hash_b[index].binary)
            if (((*read_std)->comp->from && !(ft_strncmp(hash_b[index].binary, (*read_std)->comp->from, ft_strlen((*read_std)->comp->from) - 1)))
                || !(*read_std)->comp->from)
                init_files(&((*read_std)->comp->tab_->file), hash_b[index].binary, 0, i++);
        NBR_FD(index, fdb);
        CHAR_FD(10,fdb);
    }

}
