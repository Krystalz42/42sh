/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/13 05:32:01 by aroulin           #+#    #+#             */
/*   Updated: 2017/08/30 21:02:30 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

int			print_list(int to_select, t_cmd *cmd, t_cmd *stop, t_cursor *cur)
{
	int			co;

	co = tgetco();
	while ((!to_select && cmd->c) || (to_select && cmd != stop))
	{
		(cmd->c != 10) ? CHAR_FD(cmd->c, init_fd()): 0 ;
		if (cmd->c == 10 || cur->co >= co - 1)
		{
			if (to_select)
				tputs(tgetstr(MV_BOT, 0), STDIN_FILENO, &my_put);
			else
				insert_one_line();
			cur->line += 1;
			cur->co = 0;
		}
		cur->co ++;
		cmd = cmd->next;
	}
	return (1);
}

static inline void print_to_end(t_read *read_std, t_cmd *cmd, int end)
{
	restore_cursor_(read_std->cur);
	if (!end)
		tputs(tgetstr(CLEAR_FROM_CUR, 0), STDIN_FILENO, &my_put);
	read_std->cur = prompt(PRINT);
	print_list(end, cmd, read_std->cmd, &(read_std->cur));
}

int			print_struct(t_read *read_std)
{
	t_cmd		*cmd;

	if ((read_std)->print)
	{
		tputs(tgetstr(CURSOR_INVIS, 0), STDIN_FILENO, &my_put);
		cmd = first_cmd(read_std->cmd, read_std->history);
		if ((read_std)->print == 2)
			print_to_end(read_std, cmd, 0);
		print_to_end(read_std, cmd, 1);
		tputs(tgetstr(CURSOR_BACK, 0), STDIN_FILENO, &my_put);
		(read_std)->print = 0;
	}
	return (1);
}
