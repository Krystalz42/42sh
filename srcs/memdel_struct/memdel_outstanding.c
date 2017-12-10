/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memdel_outstanding.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/24 21:06:26 by aroulin           #+#    #+#             */
/*   Updated: 2017/10/02 22:20:51 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

void		reset_os(t_outstanding **ptr)
{
	while ((*ptr)->prev)
		(*ptr) = (*ptr)->prev;
}

void		memdel_outstanding(void)
{
	t_outstanding	*ptr;
	t_outstanding	*temp;

	keep_buffer(NULL, 1);
	if ((ptr = get_os_pointer(NULL, 0)))
	{
		reset_os(&ptr);
		while (ptr)
		{
			temp = ptr;
			memdel_cmd(&(ptr->cmd));
			ptr = ptr->next;
			free(temp);
		}
	}
	get_os_pointer(NULL, 1);
}
