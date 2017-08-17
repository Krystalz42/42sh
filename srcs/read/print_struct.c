/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/13 05:32:01 by aroulin           #+#    #+#             */
/*   Updated: 2017/08/17 21:25:37 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

void		restore_cursor_(t_cursor cur)
{
	int		i;
	
	i = 0;
	while (++i < cur.co)
		MV_LEFT;
	while (cur.line--)
		MV_TOP;
}

int			print_list(int to_select, t_cmd *cmd, t_cmd *stop)
{
	if (to_select)
		while (cmd != stop)
		{
			CHAR_FD(cmd->c, init_fd());
			cmd = cmd->next;
		}
	else
		while (cmd)
		{
			CHAR_FD(cmd->c, init_fd());
			cmd = cmd->next;
		}
	return (1);
}

int			print_struct(t_read *read_std)
{
	t_cmd		*cmd;

	CURSOR_INVIS;
	cmd = first_cmd(read_std->cmd, read_std->history);
	restore_cursor_(read_std->cur);
	CLEAR_FROM_CUR;
	print_list(0, cmd, read_std->cmd);
	restore_cursor_(read_std->cur);
	print_list(1, cmd, read_std->cmd);
	CURSOR_BACK;
	return (1);
}
