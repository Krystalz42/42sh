/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_outstanding.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/24 19:49:50 by aroulin           #+#    #+#             */
/*   Updated: 2017/09/24 19:49:51 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

static t_outstanding       *create_element_os(t_cmd *cmd, unsigned long move,
                                       unsigned long buff)
{
	t_outstanding       *tmp;

	tmp = (t_outstanding *)ft_memalloc(sizeof(t_outstanding));
	tmp->cmd = cmd;
	tmp->movement = move;
	tmp->buff = buff;
	tmp->next = NULL;
	tmp->prev = NULL;
	return (tmp);
}

void                add_outstanding(t_cmd *cmd, unsigned long move,
                                    unsigned long buff)
{
	t_outstanding *element;

	if (!move)
		return ;
	keep_buffer(cmd, 0);
	dprintf(fdb, "In add outstanding [Pointer = %d][move = %lu] [buff = "
			"%lu]\n", (cmd ? 1 : 0), move, buff);
	if (!(element = get_os_pointer(NULL, 0)))
		get_os_pointer(create_element_os(cmd, move, buff), 0);
	else
	{
		element->next = create_element_os(cmd, move, buff);
		element->next->prev = element;
		get_os_pointer(element->next, 0);
	}
}