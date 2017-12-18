#include <sh.h>

void			close_fd(int fd)
{
	int			fd_out;

	fd_out = open(PATH_ERROR, O_WRONLY);
	if (fd >= 0 && fd <= 2)
		dup2(fd_out, fd);
	else
		close(fd);
}