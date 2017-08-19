/*                                                        :::      ::::::::   */
/*   read_stdin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2027/08/09 22:42:45 by aroulin           #+#    #+#             */
/*   Updated: 2027/08/20 24:57:27 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

t_cmp		compare_key[] = {
	(t_cmp){DELETE_KEY, del_key},
	(t_cmp){EOF_KEY, key_eof},
	(t_cmp){TAB_KEY, key_tab},
	(t_cmp){ENTER_KEY, key_enter_},
	(t_cmp){INTERRUPT_KEY, key_interrupt},
	(t_cmp){CLEAR_KEY, key_clear_},
	(t_cmp){HOME_KEY, home_key},
	(t_cmp){END_KEY, end_key},
	(t_cmp){DEL_KEY, del_key},
	(t_cmp){PAGE_UP, del_key},
	(t_cmp){PAGE_DOWN, del_key},
	(t_cmp){ARROW_DOWN, arrow_down},
	(t_cmp){ARROW_LEFT, arrow_left},
	(t_cmp){ARROW_RIGHT, arrow_right},
	(t_cmp){ARROW_UP, arrow_up},
	(t_cmp){HOME_KEY, home_key},
	(t_cmp){SHIFT_UP_KEY, shift_up_key},
	(t_cmp){SHIFT_DOWN_KEY, shift_down_key},
	(t_cmp){SHIFT_RIGHT_KEY, shift_right_key},
	(t_cmp){SHIFT_LEFT_KEY, shift_left_key},
	(t_cmp){NULL, NULL}
};

int				init_buff(char *buff, int *i)
{
	ft_bzero(buff, LEN_BUFFER);
	*i = -1;
	return (1);
}

t_read					*init_struct_for_read(void)
{
	t_read		*read_std;

	if (!(read_std = (t_read *)ft_memalloc(sizeof(t_read))))
		return (NULL);
	if (!(read_std->cmd = create_element('\0')))
		return (NULL);
	convert_to_cursor(read_std, prompt(DEFAULT | PRINT, "&> "));
	return (read_std);
}

t_read			*read_stdin(void)
{
	char		buff[LEN_BUFFER];
	t_read		*read_std;
	int			c;
	int			i;
	
	if (!(read_std = init_struct_for_read()))
		return (NULL);
	init_buff(buff, &i);
	set_termios(SET_OUR_TERM);
	while ((c = -1) && read(STDIN_FILENO, &(buff[++i]), sizeof(char)))
	{
		if (PRINT_KEY(buff[0]))
			key_print_(&read_std, buff[0]) && init_buff(buff, &i);
		while (compare_key[++c].key)
			if (!ft_strcmp(compare_key[c].key, buff) && init_buff(buff, &i))
				compare_key[c].function(&read_std);
		(i == 5) && init_buff(buff, &i);
		(read_std->completion) && (--read_std->completion);
		(!read_std->completion) && print_struct(read_std) && memdel_completion(&(read_std->comp));
	}
	set_termios(SET_OLD_TERM);
	return (read_std);
}
