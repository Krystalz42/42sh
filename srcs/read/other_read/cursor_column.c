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
	char	buff[7];
	int		index;
	int		col;

	ft_bzero(buff, 7);
	set_termios(SET_OUR_TERM);
	if ((write(STDIN_FILENO, CURSOR, sizeof(CURSOR))))
		read(STDIN_FILENO, buff, 7);
	index = 0;
	while (index < 7 && buff[index] != ';')
		index++;
	col = ft_atoi(buff + index + 1);
	if (col > 2 && new_line)
		ft_putstr_fd("\x1B[7m%\x1B[0m\n", init_fd());
	return (col);
}
