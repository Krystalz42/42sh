/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_are_list.c.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/05 18:21:58 by aroulin           #+#    #+#             */
/*   Updated: 2017/09/05 20:50:17 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

int         list_compare(t_cmd *little, t_cmd *big)
{
	t_cmd *tmp;

	while (big && big->c)
	{
		if (big->c == little->c)
        {
            tmp = little;
            while (big->c && tmp->c && tmp->c == big->c) {
                big = big->next;
                tmp = tmp->next;
            }
            if (tmp->c == '\0')
                return (1);
        }
		big = big->next;
	}
	return (0);
}
