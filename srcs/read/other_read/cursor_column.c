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
	char	buff[14];
	int		index;
	int		col;
	int		fd;

	fd = open(ttyname(STDIN_FILENO), O_RDWR);
	ft_bzero(buff, 14);
	set_termios(SET_OUR_TERM);
	write(fd, CURSOR, sizeof(CURSOR));
	read(fd, buff, 14);
	index = 0;
	while (index < 14 && buff[index] != ';')
		index++;
	col = ft_atoi(buff + index + 1);
	if (col > 2 && new_line)
		ft_putstr_fd("\x1B[7m%\x1B[0m\n", init_fd());
	close(fd);
	return (col);
}
