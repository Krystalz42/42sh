//
// Created by Alexandre ROULIN on 10/25/17.
//

#include <sh.h>

static const t_signal	g_signal[] = {
		(t_signal){SIGHUP, "terminal line hangup"},
		(t_signal){SIGINT, "interrupt program"},
		(t_signal){SIGQUIT, "quit program"},
		(t_signal){SIGILL, "illegal instruction"},
		(t_signal){SIGTRAP, "trace trap"},
		(t_signal){SIGABRT, "abort program"},
		(t_signal){SIGEMT, "emulate instruction executed"},
		(t_signal){SIGFPE, "floating-point exception"},
		(t_signal){SIGKILL, "kill program"},
		(t_signal){SIGBUS, "bus error"},
		(t_signal){SIGSEGV, "segmentation violation"},
		(t_signal){SIGSYS, "non-existent system call invoked"},
		(t_signal){SIGPIPE, "write on a pipe with no reader"},
		(t_signal){SIGALRM, "real-time timer expired"},
		(t_signal){SIGTERM, "software termination signal"},
		(t_signal){SIGURG, "urgent condition present on"},
		(t_signal){SIGSTOP, "suspended"},
		(t_signal){SIGTSTP, "suspended"},
		(t_signal){SIGCONT, "continued"},
		(t_signal){SIGTTIN, "suspended (tty input)"},
		(t_signal){SIGTTOU, "suspended (tty output)"},
		(t_signal){SIGIO, "I/O is possible on a descriptor"},
		(t_signal){SIGXCPU, "cpu time limit exceeded"},
		(t_signal){SIGXFSZ, "file size limit exceeded"},
		(t_signal){SIGVTALRM, "virtual time alarm"},
		(t_signal){SIGPROF, "profiling timer alarm"},
		(t_signal){SIGUSR1, "User defined signal 1"},
		(t_signal){SIGUSR2, "User defined signal 2"},
		(t_signal){0, NULL}
};

const char				*status_signal(int signal)
{
	int			index;

	log_warn("Status in [%d] status_signal(int signal)", signal);
	index = 0;
	while (g_signal[index].signal)
	{
		if (signal == g_signal[index].signal)
			return (g_signal[index].status);
		index++;
	}
	return (NULL);
}

const char				*status_exit(int signal)
{
	static char		status[8];
	char			*temp;

	ft_bzero(status, 8);
	if (signal)
	{
		temp = ft_itoa(signal);
		strcpy(status, "exit");
		strcpy(status + 5, temp);
		free(temp);
	}
	else
	{
		strcpy(status, "done");
	}
	return (status);
}
