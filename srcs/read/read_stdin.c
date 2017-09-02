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
	(t_cmp){DELETE_KEY, key_del},
	(t_cmp){EOF_KEY, key_eof},
	(t_cmp){TAB_KEY, key_tab},
	(t_cmp){ENTER_KEY, key_enter_},
	(t_cmp){INTERRUPT_KEY, key_interrupt},
	(t_cmp){CLEAR_KEY, key_clear_},
	(t_cmp){HOME_KEY, key_home_},
	(t_cmp){END_KEY, key_end_},
	(t_cmp){DEL_KEY, key_delete_here},
	(t_cmp){PAGE_UP, key_del},
	(t_cmp){PAGE_DOWN, key_del},
	(t_cmp){ARROW_DOWN, key_arrow_down},
	(t_cmp){ARROW_LEFT, key_arrow_left},
	(t_cmp){ARROW_RIGHT, key_arrow_right},
	(t_cmp){ARROW_UP, key_arrow_up},
	(t_cmp){HOME_KEY, key_home_},
	(t_cmp){CTRL_R, key_home_},
	(t_cmp){SHIFT_UP_KEY, key_shift_up},
	(t_cmp){SHIFT_DOWN_KEY, key_shift_down},
	(t_cmp){SHIFT_RIGHT_KEY, key_shift_right},
	(t_cmp){SHIFT_LEFT_KEY, key_shift_left},
	(t_cmp){NULL, NULL}
};

int				init_buff(char *buff, int *i, t_read **read_std)
{
	ft_bzero(buff, LEN_BUFFER);
	*i = -1;
	((*read_std)->completion) && (--(*read_std)->completion);
	(!(*read_std)->completion) && print_struct((*read_std)) && memdel_completion(&((*read_std)->comp));
	return (1);
}

t_read					*init_struct_for_read(void)
{
	t_read		*read_std;

	if (!(read_std = (t_read *)ft_memalloc(sizeof(t_read))))
		return (NULL);
	if (!(read_std->cmd = create_element('\0')))
		return (NULL);
	gbl_save_read(read_std->cmd);
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
	read_std->cur.co = prompt(DEFAULT, "KOUKOU TOI &> ");
	init_buff(buff, &i, &read_std);
	set_termios(SET_OUR_TERM);
	while ((c = -1) && read(STDIN_FILENO, &(buff[++i]), sizeof(char)))
	{
		if (PRINT_KEY(buff[0]))
			key_print_(&read_std, buff[0]) && init_buff(buff, &i, &read_std);
		while (compare_key[++c].key)
			if (!ft_strcmp(compare_key[c].key, buff))
				compare_key[c].function(&read_std) && init_buff(buff, &i, &read_std);
		if ((read_std)->finish)
			break ; 
	}
	set_termios(SET_OLD_TERM);
	finish_read_std(&read_std);
	return (read_std);
}
