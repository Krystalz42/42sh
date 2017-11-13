//
// Created by Alexandre ROULIN on 11/13/17.
//

#include <sh.h>

int			print_process(t_process *process,int option, int index)
{
	if (process->pid == process->pgid)
		ft_printf("[%d]\t", index);
	else if (option & 1 && process->pid != process->pgid)
		return (1);
	else
		ft_putchar('\t');
	if (option & 8)
		ft_printf("\t%d %d %s %s\n", process->pid, process->pgid,
				  process->running ? RUN : STOP, process->command);
	else if (option & 16)
		ft_printf("\t%s %s\n", CONTINUED, process->command);
	else
		ft_printf("\t%s %s\n", process->running ? RUN : STOP, process->command);
	return (1);
}

uint8_t		print_jobs(t_jobs *jobs, int option)
{
	t_process			*process;

	process = jobs->process;
	while (process)
	{
		if ((option & 2) && process->running)
			print_process(process, option, jobs->index);
		else if ((option & 4) && process->running == false)
			print_process(process, option, jobs->index);
		else if (!(option & 2) && !(option & 4))
			print_process(process, option, jobs->index);
		process = process->next;
	}
	return (0);
}

void			print_status(t_process *process, int jobs_spec)
{
	log_warn("/!\\  [PROCESS %d WILL BE PRINT]] /!\\", jobs_spec);
	cursor_column(1);
	while (process)
	{
		process->prev != NULL ? CHAR('\t') : ft_printf("[%d]\t", jobs_spec + 1);
		if (WIFEXITED(process->status))
			ft_printf("%d %s %s\n", process->pid, status_exit(WEXITSTATUS(process->status)), process->command);
		else if (WIFSIGNALED(process->status))
			ft_printf("%d %s %s\n", process->pid, status_signal(WTERMSIG(process->status)), process->command);
		else if (WIFCONTINUED(process->status))
			ft_printf("%d %s %s\n", process->pid, status_signal(18), process->command);
		else if (WIFSTOPPED(process->status))
			ft_printf("%d %s %s\n", process->pid, status_signal(WSTOPSIG(process->status)), process->command);
		process = process->next;
	}
	ioctl(STDIN_FILENO, TIOCSTI, "\0");
}

void		print_info_jobs(t_jobs *jobs)
{
	t_process *process;

	process = jobs->process;
	ft_printf("[%d] ", jobs->index);
	while (process)
	{
		ft_putnbr(process->pid);
		ft_putchar(32);
		process = process->next;
	}
	ft_putchar(10);
}