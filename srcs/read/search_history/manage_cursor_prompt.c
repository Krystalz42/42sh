/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_cursor_prompt.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 17:39:18 by aroulin           #+#    #+#             */
/*   Updated: 2017/09/04 17:39:27 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

int				new_line_after_bloc(t_read **read_std, int to)
{
	int		save;

	if (to == 2)
	{
		save = (*read_std)->cur.line;
		reset(read_std, 0);
		(*read_std)->cur.line = save;
		insert_one_line();

	}
	else if (to == 1)
	{
		save = (*read_std)->cur.line;
		reset(read_std, 0);
		(*read_std)->cur.line = save;
		tputs(tgetstr(MV_BOT, 0), STDIN_FILENO, &my_put);
	}
	else
	{
		tputs(tgetstr(MV_TOP, 0), STDIN_FILENO, &my_put);
		reset(read_std, 1);
	}
	return (1);
}

t_cursor				prompt_history(int p)
{
	static const char	prompt[] = "search in history : ";
	t_cursor			cur;
	int 				co;

	co = tgetco();
	if (p)
		STR_FD("\x1B[31m", 2);
	STR_FD(prompt, 2);
	P_RST_FD(2);
	cur.line = ((int)ft_strlen(prompt) / co) + 1;
	cur.co = ((int)ft_strlen(prompt) % co);
	return (cur);
}
