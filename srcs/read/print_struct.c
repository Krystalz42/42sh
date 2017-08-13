/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/13 05:32:01 by aroulin           #+#    #+#             */
/*   Updated: 2017/08/13 06:01:09 by aroulin          ###   ########.fr       */
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

void		print_list(int to_select, t_cmd *cmd)
{
	if (to_select)
	{
		while (cmd)
		{
			CHAR_FD(cmd->c, init_fd());
			if (cmd->next->s)
				break ;
			cmd = cmd->next;
		}
	}
	else
	{
		while (cmd)
		{
			CHAR_FD(cmd->c, init_fd());
			cmd = cmd->next;
		}

	}
}

int			print_struct(t_read *read_std)
{
	t_cmd		*cmd;
	CURSOR_INVIS;
	cmd = first_cmd(read_std->cmd, read_std->history);
	restore_cursor_(read_std->cur);
	print_list(0, cmd);
	restore_cursor_(read_std->cur);
	print_list(1, cmd);
	CURSOR_BACK;
	return (1);
}
