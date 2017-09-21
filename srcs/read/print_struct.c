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

	co = tgetnum("co");
	cur->line = 1;
	while ((!to_select && cmd->c) || (to_select && cmd != stop))
	{
		if (cmd->c == 10 || cur->co >= co)
		{
			(to_select) ? MV_BOT : insert_one_line();
			cur->line += 1;
			cur->co = 0;
		}
		(cmd->c != 10) ? CHAR_FD(cmd->c, 2): 0 ;
		cur->co += (cmd->c == 9) ? 4 : 1;
		cmd = cmd->next;
	}
	return (1);
}

inline int	reset_cur(t_cursor *cur)
{
	cur->line = 0;
	cur->co = 0;
	return (1);
}

int			print_struct(t_read *read_std)
{
	t_cmd		*cmd;

	CURSOR_INVIS;
	cmd = first_cmd(read_std->cmd, read_std->history);
	restore_cursor_(read_std->cur);
	CLEAR_FROM_CUR;
	reset_cur(&(read_std->cur));
	read_std->cur.co = prompt(PRINT);
	print_list(0, cmd, read_std->cmd, &(read_std->cur));
	restore_cursor_(read_std->cur);
	reset_cur(&(read_std->cur));
	read_std->cur.co = prompt(PRINT);
	print_list(1, cmd, read_std->cmd, &(read_std->cur));
	CURSOR_BACK;
    return (1);
}
