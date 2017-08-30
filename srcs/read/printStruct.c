/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printStruct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/13 05:32:01 by aroulin           #+#    #+#             */
/*   Updated: 2017/08/30 21:02:30 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

void		restoreCursor(t_cursor cur)
{
	BACK_N;
	while (--cur.co >= 0)
	{
		MV_LEFT;
	}
	while (--cur.line > 0)
	{
		MV_TOP;
	}
}

int			printList(int to_select, t_cmd *cmd, t_cmd *stop, t_read *readStd)
{
	int			co;

	co = tgetnum("co");
	readStd->cur.co = prompt(PRINT, NULL);
	readStd->cur.line = 1;
	while ((!to_select && cmd && cmd->c) || (to_select && cmd != stop))
	{
		if (cmd->c == 10 || readStd->cur.co == co)
		{
			(to_select) ? MV_BOT : insertOneLine();
			readStd->cur.line += 1;
			readStd->cur.co = 0;
		}
		(cmd->c != 10) ? CHAR_FD(cmd->c, initFd()): 0 ;
		readStd->cur.co += (cmd->c == 9) ? 4 : 1;
		cmd = cmd->next;
	}
	return (1);
}

int	reset_cur(t_read *readStd)
{
	readStd->cur.line = 0;
	readStd->cur.co = 0;
	return (1);
}

int			printStruct(t_read *readStd)
{
	t_cmd		*cmd;

	CURSOR_INVIS;
	cmd = firstCmd(readStd->cmd, readStd->history);
	restoreCursor(readStd->cur);
	CLEAR_FROM_CUR;
	reset_cur(readStd);
	printList(0, cmd, readStd->cmd, readStd);
	restoreCursor(readStd->cur);
	reset_cur(readStd);
	printList(1, cmd, readStd->cmd, readStd);
	CURSOR_BACK;
	return (1);
}
