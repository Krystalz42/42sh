//
// Created by Alexandre ROULIN on 10/23/17.
//

#include <sh.h>

int		key_refresh_(t_read **read_std, unsigned long buff)
{
	(void)buff;
	(*read_std)->history_search++;
	(*read_std)->completion++;
	(*read_std)->print = 2;
	return (1);
}