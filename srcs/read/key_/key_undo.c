/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_undo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/24 21:12:14 by aroulin           #+#    #+#             */
/*   Updated: 2017/11/17 16:45:57 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

t_cmp			g_to_do[] = {
		(t_cmp){PRINT_KEY, key_del_buff},
		(t_cmp){DELETE_KEY, key_reprint},
		(t_cmp){HOME_KEY, key_end_},
		(t_cmp){END_KEY, key_home_},
		(t_cmp){DEL_KEY, key_reprint},
		(t_cmp){CTRL_D, key_home_},
		(t_cmp){CTRL_B, key_arrow_right},
		(t_cmp){CTRL_E, key_home_},
		(t_cmp){CTRL_K, key_reprint},
		(t_cmp){CTRL_A, key_end_},
		(t_cmp){CTRL_F, key_arrow_left},
		(t_cmp){META_U, key_downcase_word},
		(t_cmp){META_C, capitalize_word_undo},
		(t_cmp){META_L, key_upcase_word},
		(t_cmp){META_DEL, key_reprint},
		(t_cmp){META_D, key_reprint},
		(t_cmp){META_B, key_shift_right},
		(t_cmp){META_F, key_shift_left},
		(t_cmp){ARROW_LEFT, key_arrow_right},
		(t_cmp){ARROW_RIGHT, key_arrow_left},
		(t_cmp){SHIFT_UP_KEY, key_shift_down},
		(t_cmp){SHIFT_DOWN_KEY, key_shift_up},
		(t_cmp){SHIFT_RIGHT_KEY, key_shift_left},
		(t_cmp){SHIFT_LEFT_KEY, key_shift_right},
		(t_cmp){0, NULL}
};

static void		place_new_undo(t_outstanding *undo)
{
	t_outstanding *to_kill;

	to_kill = undo;
	if (undo->prev)
	{
		undo = undo->prev;
		undo->next = NULL;
		ft_memdel((void **)&to_kill);
		get_os_pointer(undo, 0);
	}
	else
	{
		ft_memdel((void **)&to_kill);
		get_os_pointer(undo, 1);
	}
}

int				key_undo_(t_read **read_std, unsigned long buff)
{
	t_outstanding		*undo;
	int					i;

	i = -1;
	(void)buff;
	if ((undo = get_os_pointer(NULL, 0)))
	{
		log_trace("Find undo");
		while (g_to_do[++i].key)
			if (g_to_do[i].key == undo->movement)
			{
				if (undo->movement == META_U || undo->movement == META_L)
					key_shift_left(read_std, 0);
				g_to_do[i].function(read_std, 0);
				if (undo->movement == META_U || undo->movement == META_L)
					key_shift_left(read_std, 0);
			}
		place_new_undo(undo);
	}
	(*read_std)->print = 2;
	return (1);
}
