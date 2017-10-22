/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_struct_history.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 17:37:01 by aroulin           #+#    #+#             */
/*   Updated: 2017/09/04 19:39:25 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

void         print_in_search_history(t_read *read_std)
{
	t_cmd       *cmd;

	tputs(tgetstr(CURSOR_INVIS, 0), STDIN_FILENO, &my_put);
	cmd = first_cmd(read_std->hist_search->cmd, 1);
	tputs(tgetstr(CLEAR_FROM_CUR, 0), STDIN_FILENO, &my_put);
	read_std->hist_search->cur = prompt_history(last_resultat(-42));
	print_list(1, cmd, read_std->hist_search->cmd, &(read_std->hist_search->cur));
    CHAR_FD('_', 2);
	restore_cursor_(read_std->hist_search->cur);
    tputs(tgetstr(CURSOR_BACK, 0), STDIN_FILENO, &my_put);
}

int		print_struct_history(t_read **read_std)
{
	if (!(*read_std)->history_search)
		new_line_after_bloc(read_std, 2);
	else
		new_line_after_bloc(read_std, 1);
	print_in_search_history(*read_std);
	new_line_after_bloc(read_std, 0);
	return (1);
}