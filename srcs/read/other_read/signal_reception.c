//
// Created by Alexandre ROULIN on 10/16/17.
//

#include <sh.h>

int				signal_reception(int brk)
{
	static int		save;

	if (brk != -1)
		save = brk;
	return (save);
}