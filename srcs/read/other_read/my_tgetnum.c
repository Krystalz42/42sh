//
// Created by Alexandre ROULIN on 11/2/17.
//

#include <sh.h>

int			tgetco(void)
{
	struct winsize ms;

	ioctl(0, TIOCGWINSZ, &ms);
	return (ms.ws_col);
}

int			tgetli(void)
{
	struct winsize ms;

	ioctl(0, TIOCGWINSZ, &ms);
	return (ms.ws_row);
}