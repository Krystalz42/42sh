/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_column.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 16:44:20 by gbourson          #+#    #+#             */
/*   Updated: 2017/11/17 16:44:36 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

int			cursor_column(int new_line)
{
	char	buff[14];
	int		index;
	int		col;

	ft_bzero(buff, 9);
	set_termios(SET_OUR_TERM);
	write(STDERR_FILENO, CURSOR, sizeof(CURSOR));
	read(STDERR_FILENO, buff, 14);
	index = -1;
	while (++index < 9 && buff[index] != ';')
		;
	col = ft_atoi(buff + index + 1);
	log_info("%d", col);
	if (col > 2 && new_line)
	{
		ft_putstr_fd("\x1B[7m%\x1B[0m", init_fd());
		ft_putchar('\n');
	}
	return (col);
}
