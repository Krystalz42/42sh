#include <string.h>
#include <signal.h>
#include <fcntl.h>
#include <unistd.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <fcntl.h>
#include <curses.h>
#include <term.h>
#include <stdbool.h>
#include <sys/types.h>
#include <dirent.h>

void		handler(int sig)
{
	dprintf(2, "In SIGNAL [%d] PID [%d] DADDY [%d]\n",sig, getpid(),getppid()); 
	signal(sig, SIG_DFL);
	kill(sig, getpid());
}

int main(void)
{
	int i = -1;
	while (++i < 32)
		signal(i, &handler);

	dprintf(2, "[IN SOFT 3] PID = [%d] PPID = [%d]\n",getpid(),getppid()); 
	pause();
	pause();
	pause();
    exit(EXIT_SUCCESS);
	return (1);
}
