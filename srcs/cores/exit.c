//
// Created by Alexandre ROULIN on 10/27/17.
//

#include <sh.h>

void			exit_(void)
{
	b_write_history_in_file(get_str_from_history());
	ft_putendl("exit");
	exit(var_return(-1));
}