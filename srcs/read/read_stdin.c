/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_stdin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 22:42:45 by aroulin           #+#    #+#             */
/*   Updated: 2017/08/10 02:32:43 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>
t_cmp		compare_key[] = {
	(t_cmp){SPECIAL_KEY, 0},
	(t_cmp){DELETE_KEY, 0},
	(t_cmp){EOF_KEY, 0},
	(t_cmp){TAB_KEY, 0},
	(t_cmp){CLEAR_KEY, 0},
	(t_cmp){INTERRUPT_KEY, 0},
	(t_cmp){'\0', NULL}
};

t_read			*read_stdin(void)
{
	char		buffer;
	t_read		*read_std = 0;
	int			i;
	
	while ((i = -1) && read(STDIN_FILENO, &buffer, sizeof(char)))
	{
		if (buffer == 13)
			break;
		if (buffer == 33)
			STR("WTFFFFFFF");
		if (PRINT_KEY(buffer))
			;
		else
			while (compare_key[++i].key)
				if (compare_key[i].key == buffer)
					compare_key[i].function(&read_std);

	}
	return (read_std);
}
