/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memdel_outstanding.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/24 21:06:26 by aroulin           #+#    #+#             */
/*   Updated: 2017/09/24 21:06:27 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

void        reset_os(t_outstanding **ptr)
{
	while ((*ptr)->prev)
		(*ptr) = (*ptr)->prev;
}

void        memdel_outstanding(void)
{
	t_outstanding *ptr;
	t_outstanding *tmp;

	if ((ptr = get_os_pointer(NULL, 0)))
	{
		reset_os(&ptr);
		while (ptr)
		{
			tmp = ptr;
			memdel_cmd(&(ptr->cmd));
			ptr = ptr->next;
			free(tmp);
		}
	}
	get_os_pointer(NULL, 1);
}