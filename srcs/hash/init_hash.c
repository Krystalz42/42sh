/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_hash.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 17:14:09 by aroulin           #+#    #+#             */
/*   Updated: 2017/09/19 17:14:10 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

//static void		convert_to_hash(char *buff, int ret)
//{
//    int     i;
//
//    i = -1;
//    while (++i < ret)
//    {
//        buff++;
//    }
//}

void        init_hash(void)
{
    char    *path_hash;
    int     fd;
    char    buff[10000];

    if (!(path_hash = get_str_from_hash()))
        return ;
    if ((fd = open(path_hash, O_RDONLY) == -1))
        return ;
    ft_bzero(buff, 10000);
    free(path_hash);
}