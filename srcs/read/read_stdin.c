/*                                                        :::      ::::::::   */
/*   read_stdin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 22:42:45 by aroulin           #+#    #+#             */
/*   Updated: 2017/08/10 23:57:17 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>
t_cmp		compare_key[] = {
	(t_cmp){SPECIAL_KEY, special_key},
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
	
	set_termios(SET_OUR_TERM);
	while ((i = -1) && read(STDIN_FILENO, &buffer, sizeof(char)))
	{
		NBR(buffer);
		CHAR(' ');
		if (buffer == 13)
			break;
		if (PRINT_KEY(buffer))
			;
		else
			while (compare_key[++i].key)
				if (compare_key[i].key == buffer)
				{
			//		compare_key[i].function(&read_std);
				}

	}
	return (read_std);
}
