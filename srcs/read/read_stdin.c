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

t_cmp		g_tab_are_key[] = {
    (t_cmp){DELETE_KEY, key_del},
    (t_cmp){CTRL_D, key_eof},
    (t_cmp){TAB_KEY, key_tab},
    (t_cmp){ENTER_KEY, key_enter_},
    (t_cmp){INTERRUPT_KEY, key_interrupt},
    (t_cmp){CLEAR_KEY, key_clear_},
    (t_cmp){HOME_KEY, key_home_},
    (t_cmp){CTRL_A, key_home_},
    (t_cmp){END_KEY, key_end_},
    (t_cmp){CTRL_E, key_end_},
    (t_cmp){DEL_KEY, key_delete_here},
    (t_cmp){PAGE_UP, key_del},
    (t_cmp){PAGE_DOWN, key_del},
    (t_cmp){ARROW_DOWN, key_arrow_down},
    (t_cmp){CTRL_B, key_arrow_left},
    (t_cmp){ARROW_LEFT, key_arrow_left},
    (t_cmp){ARROW_RIGHT, key_arrow_right},
    (t_cmp){CTRL_F, key_arrow_right},
    (t_cmp){ARROW_UP, key_arrow_up},
    (t_cmp){HOME_KEY, key_home_},
    (t_cmp){CTRL_R, key_search_history},
    (t_cmp){SHIFT_UP_KEY, key_shift_up},
    (t_cmp){SHIFT_DOWN_KEY, key_shift_down},
    (t_cmp){SHIFT_RIGHT_KEY, key_shift_right},
    (t_cmp){SHIFT_LEFT_KEY, key_shift_left},
    (t_cmp){META_F, key_shift_right},
    (t_cmp){META_B, key_shift_left},
    (t_cmp){CTRL_UNDO, key_undo_},
    (t_cmp){0, key_print_}
};

static inline int		chk_and_print(unsigned long *buff, t_read **read_std)
{
    (*buff) = 0;
    ((*read_std)->completion) ? (--(*read_std)->completion) :
        memdel_completion(&((*read_std)->tab_));
    ((*read_std)->history_search) ? (--(*read_std)->history_search) :
        memdel_lfh(&((*read_std)->hist_search));
    (!(*read_std)->completion) ? print_struct(*read_std) : 0;
    ((*read_std)->history_search) ? print_struct_history(read_std) : 0;
    (*read_std)->print = 0;
    return (1);
}

static inline void      initialize_fct(t_read **read_std, unsigned long *buff)
{
    init_prompt();
    init_signal();
    set_termios(SET_OUR_TERM);
    (*read_std)->cur.co = prompt(DEFAULT | PRINT);
    last_resultat(0);
    chk_and_print(buff, read_std);
	get_os_pointer(NULL, 1);
}

t_read					*read_stdin(void)
{
    t_read		*read_std;
    int			index;
    unsigned long buff;

    if (!(read_std = init_struct_for_read()))
        return (NULL);
    initialize_fct(&read_std, &buff);
    while ((index = -1) && read(STDIN_FILENO, &buff, sizeof(unsigned long)))
    {
	    dprintf(fdb, "%lu\n", buff);
	    CHAR_FD(10,fdb);
        while (g_tab_are_key[++index].key && g_tab_are_key[index].key != buff)
	        ;
	    g_tab_are_key[index].function(&read_std, buff);
        chk_and_print(&buff, &read_std);
        if ((read_std)->finish)
            break ;
    }
    set_termios(SET_OLD_TERM);
    finish_read_std(&read_std);
    NL;
    return (read_std);
}
