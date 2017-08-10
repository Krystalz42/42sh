/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_key.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 02:02:59 by aroulin           #+#    #+#             */
/*   Updated: 2017/08/10 02:33:16 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

t_cmp		compare_special_key[] = {
	(t_cmp){ARROW_UP, 0},
		(t_cmp){ARROW_DOWN, 0},
		(t_cmp){ARROW_LEFT, 0},
		(t_cmp){ARROW_RIGHT, 0},
		(t_cmp){END_KEY, 0},
		(t_cmp){HOME_KEY, 0},
		(t_cmp){DEL_KEY, 0},
		(t_cmp){'\0', NULL}
};

t_cmp		compare_special_key2[] = {
	(t_cmp){ARROW_UP, 0},
		(t_cmp){SHIFT_UP_KEY, 0},
		(t_cmp){SHIFT_DOWN_KEY, 0},
		(t_cmp){SHIFT_RIGHT_KEY, 0},
		(t_cmp){SHIFT_LEFT_KEY, 0},
		(t_cmp){'\0', NULL}
};


int			special_key(t_read **read_std)
{
	int		i;
	int		c;
	char	buffer;

	c = -1;
	while ((i = -1) && read(STDIN_FILENO, &buffer, sizeof(char)) && ++c >= 0)
	{
		STR("IN SPECIAL KEY\n");
		while ((c == 1) && compare_special_key[++i].key)
			if (compare_special_key[i].key == buffer)
				return (compare_special_key[i].function(read_std));
		i = -1;
		while ((c == 4) && compare_special_key2[++i].key)
			if (compare_special_key2[i].key == buffer)
				return (compare_special_key2[i].function(read_std));

	}
	return (1);
}
