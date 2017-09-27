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
		(t_do){PRINT_KEY, key_del_buff},
		(t_do){DELETE_KEY, key_reprint},
		(t_do){HOME_KEY, key_end_},
		(t_do){END_KEY, key_home_},
		(t_do){CTRL_A, key_end_},
		(t_do){CTRL_E, key_home_},
		(t_do){DEL_KEY, key_reprint},
		(t_do){SHIFT_UP_KEY, key_shift_down},
		(t_do){SHIFT_DOWN_KEY, key_shift_up},
		(t_do){SHIFT_RIGHT_KEY, key_shift_left},
		(t_do){SHIFT_LEFT_KEY, key_shift_right},
		(t_do){META_F, key_shift_left},
		(t_do){META_B, key_shift_right},
		(t_do){CTRL_K, key_reprint},
		(t_do){META_D, key_reprint},
		(t_do){0, NULL}
};

static void place_new_undo(t_outstanding *undo)
{
	t_outstanding *to_kill;

	to_kill = undo;
	if (undo->prev)
	{
		undo = undo->prev;
		ft_memdel((void **)&to_kill);
		get_os_pointer(undo, 0);
	}
	else
	{
		ft_memdel((void **)&to_kill);
		get_os_pointer(undo, 1);
	}
}

int         key_undo_(t_read **read_std, unsigned long buff)
{
	t_outstanding   *undo;
	int             i;

	i = -1;
	(void)buff;
	if ((undo = get_os_pointer(NULL, 0)))
	{
		dprintf(fdb, "In undo_key [move = %lu] [buff = %lu]\n", undo->movement,
		        undo->buff);
		while (to_do[++i].cmd)
			if (to_do[i].cmd == undo->movement)
				to_do[i].function(read_std, 0);
		place_new_undo(undo);
	}
	return (1);
}