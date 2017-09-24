/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_hash.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 17:14:09 by aroulin           #+#    #+#             */
/*   Updated: 2017/09/23 19:52:58 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

void        init_hash(void)
{
    char    *path_hash;
    int     fd;

    if (!(path_hash = get_str_from_hash()))
        return ;
    if ((fd = open(path_hash, O_RDONLY) == -1))
        free(path_hash);
}
