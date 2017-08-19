/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/13 05:32:01 by aroulin           #+#    #+#             */
/*   Updated: 2017/08/19 16:33:11 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

void		restore_cursor_(t_cursor cur)
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

int			print_list(int to_select, t_cmd *cmd, t_cmd *stop)
{
	int			i;

	i = prompt(PRINT, NULL);
	if (to_select)
		while (cmd && cmd->c && cmd != stop)
		{
			CHAR_FD(cmd->c, init_fd());
			cmd = cmd->next;
			i++;
		}
	else
		while (cmd && cmd->c)
		{
			CHAR_FD(cmd->c, init_fd());
			cmd = cmd->next;
			i++;
		}
	return (i);
}

int			convert_to_cursor(t_read *read_std, int i)
{
	int				co;

	co = tgetnum("co");
	read_std->cur.line += (co) ? i / (co) : 0;
	read_std->cur.co += co;
	return (1);
}

int	reset_cur(t_read *read_std)
{
	read_std->cur = (t_cursor){0, 0};
	return (1);
}

int			print_struct(t_read *read_std)
{
	t_cmd		*cmd;

	cmd = first_cmd(read_std->cmd, read_std->history);
	restore_cursor_(read_std->cur);
	CLEAR_FROM_CUR;
	reset_cur(read_std);
	convert_to_cursor(read_std, print_list(0, cmd, read_std->cmd));
	restore_cursor_(read_std->cur);
	reset_cur(read_std);
	convert_to_cursor(read_std, print_list(1, cmd, read_std->cmd));
	return (1);
}
