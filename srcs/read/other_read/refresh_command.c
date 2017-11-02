//
// Created by Alexandre ROULIN on 11/2/17.
//

#include <sh.h>

int			refresh_command(t_read **read_std, unsigned long buff)
{
	tputs(tgetstr(CLEAR, 0), STDIN_FILENO, &my_put);
	(*read_std)->print = 2;
}
