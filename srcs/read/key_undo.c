/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_undo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/24 21:12:14 by aroulin           #+#    #+#             */
/*   Updated: 2017/09/24 21:12:15 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

t_do        to_do[]={
		(t_do){ARROW_LEFT, key_arrow_right},
		(t_do){ARROW_RIGHT, key_arrow_left},
		(t_do){PRINT_KEY, key_del},
		(t_do){DELETE_KEY, }
		(t_do){0, 0}
};

int         key_undo_(t_read **read_std, unsigned long buff)
{
	t_outstanding   *undo;
	int             i;

	i = -1;
	(void)buff;
	if ((undo = get_os_pointer(NULL, 0)))
	{
		while (to_do[++i].cmd)
			if (to_do[i].cmd == undo->movement)
				to_do[i].function(read_std, 0);

		if (undo->prev)
			get_os_pointer(undo->prev, 0);
	}
	return (1);
}