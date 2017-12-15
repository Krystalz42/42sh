/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_column.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 16:44:20 by gbourson          #+#    #+#             */
/*   Updated: 2017/11/20 22:48:24 by sbelazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

int			cursor_column(int new_line)
{
	char	buff[10];
	int		index;
	int		col;

	if (*shell_interectative())
	{
		ft_bzero(buff, 10);
		set_termios(SET_OUR_TERM);
		if ((write(STDIN_FILENO, CURSOR, sizeof(CURSOR))))
			read(STDIN_FILENO, buff, 10);
		index = 0;
		while (index < 10 && buff[index] != ';')
			index++;
		col = (index + 1 < 10) ? ft_atoi(buff + index + 1) : 1;
		if (col > 2 && new_line)
			ft_putstr_fd("\x1B[7m%\x1B[0m\n", init_fd());
		return (col);
	}
	else
		return (0);
}
