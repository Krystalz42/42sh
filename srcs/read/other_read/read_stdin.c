/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_stdin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 14:40:38 by aroulin           #+#    #+#             */
/*   Updated: 2017/09/24 17:33:41 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

static const t_cmp		g_tab_are_key[] = {
		(t_cmp){DELETE_KEY, key_del},
		(t_cmp){TAB_KEY, key_tab},
		(t_cmp){CLEAR_KEY, key_clear_},
		(t_cmp){HOME_KEY, key_home_},
		(t_cmp){DEL_KEY, key_delete_here},
		(t_cmp){END_KEY, key_end_},
		(t_cmp){CTRL_D, key_eof},
		(t_cmp){CTRL_B, key_arrow_left},
		(t_cmp){CTRL_E, key_end_},
		(t_cmp){CTRL_R, key_search_history},
		(t_cmp){CTRL_K, key_kill_k},
		(t_cmp){CTRL_A, key_home_},
		(t_cmp){CTRL_UNDO, key_undo_},
		(t_cmp){CTRL_F, key_arrow_right},
		(t_cmp){META_U, key_upcase_word},
		(t_cmp){META_L, key_downcase_word},
		(t_cmp){META_C, key_capitalize_word},
		(t_cmp){META_Y, key_yank},
		(t_cmp){META_DEL, key_kill_prev_word},
		(t_cmp){META_D, key_kill_word},
		(t_cmp){META_B, key_shift_left},
		(t_cmp){META_F, key_shift_right},
		(t_cmp){ARROW_LEFT, key_arrow_left},
		(t_cmp){ARROW_RIGHT, key_arrow_right},
		(t_cmp){ARROW_UP, key_arrow_up},
		(t_cmp){ARROW_DOWN, key_arrow_down},
		(t_cmp){CTRL_B, key_arrow_up},
		(t_cmp){CTRL_N, key_arrow_down},
		(t_cmp){SHIFT_UP_KEY, key_shift_up},
		(t_cmp){SHIFT_DOWN_KEY, key_shift_down},
		(t_cmp){SHIFT_RIGHT_KEY, key_shift_right},
		(t_cmp){SHIFT_LEFT_KEY, key_shift_left},
		(t_cmp){0, NULL}
};

static inline int		chk_and_print(t_read **read_std)
{
	print_struct(*read_std);
	if ((*read_std)->completion)
		(*read_std)->completion -= 1;
	if ((*read_std)->history_search)
		(*read_std)->history_search -= 1;
	if ((*read_std)->history_search)
		print_struct_history(read_std);
	(*read_std)->print = 0;
	return (1);
}

static inline void		inline_print_(t_read **read_std, unsigned long *buff)
{
	key_print_(read_std, buff);
	log_trace("(*read_std)->finish %d",(*read_std)->finish);
	if ((*read_std)->finish == 0)
		chk_and_print(read_std);
}

static inline void		initialize_fct(t_read **read_std, unsigned char flags,
										 unsigned long *buff)
{
	(*read_std) = init_struct_for_read();
	log_trace("Init read_std begin");
	init_prompt();
	init_signal();
	set_termios(SET_OUR_TERM);
	(*read_std)->cur = prompt(flags | PRINT);
	signal_reception(0);
	get_os_pointer(NULL, 1);
	inline_print_(read_std, buff);
}
static char 			*finitialize_fct(t_read **read_std)
{
	set_termios(SET_OLD_TERM);
	return (finish_read_std(read_std));

}
static inline void		inline_other(t_read **read_std, unsigned long *buff, int(*fct)(t_read **, unsigned long))
{
	fct(read_std, *buff);
	chk_and_print(read_std);
	*buff = 0;
}

char					*read_stdin(unsigned char flags)
{
	t_read						*read_std;
	int							index;
	static unsigned long		buf;

	initialize_fct(&read_std, flags, &buf);
	while (!read_std->finish && read(STDIN_FILENO, &buf, sizeof(unsigned long)))
	{
		index = -1;
		log_trace("In read [%lu]",buf);
		if (ft_isprint(buf % (UCHAR_MAX + 1)) || ft_iscrlf(buf % (UCHAR_MAX + 1)))
			inline_print_(&read_std, &buf);
		while (g_tab_are_key[++index].key)
			if (g_tab_are_key[index].key == buf)
				inline_other(&read_std, &buf, g_tab_are_key[index].function);
		if ((read_std)->finish || signal_reception(-1))
			break ;
		buf = 0;
	}
	return (finitialize_fct(&read_std));
}
