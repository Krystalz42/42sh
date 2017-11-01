//
// Created by Alexandre ROULIN on 11/1/17.
//

#include <sh.h>

int				read_pipe(int *fildes)
{
	if (fildes)
	{
		close(fildes[1]);
		dup2(fildes[0], STDIN_FILENO);
		close(fildes[0]);
	}
	return (1);
}

int				write_pipe(int *fildes)
{
	if (fildes)
	{
		close(fildes[0]);
		dup2(fildes[1], STDOUT_FILENO);
		close(fildes[1]);
	}
	return (1);
}

int				close_pipe(int *fildes)
{
	if (fildes)
	{
		close(fildes[0]);
		close(fildes[1]);
	}
	return (1);
}