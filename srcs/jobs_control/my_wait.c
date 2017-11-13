//
// Created by Alexandre ROULIN on 10/6/17.
//

#include <sh.h>

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

void			set_fildes(pid_t pgid)
{
	signal(SIGTTIN, SIG_IGN);
	signal(SIGTTOU, SIG_IGN);
	log_trace("FG Return tcsetpgrp(0, %d) == [%d]", pgid, tcsetpgrp(STDIN_FILENO, pgid));
}
void			wait_process(t_jobs *jobs)
{
	t_process		*temp;

	temp = jobs->process;
	while (temp)
	{
		log_warn("%d",temp->pid);
		log_error("Wait [%d]", waitpid(-temp->pgid, &temp->status, WUNTRACED));
		temp = temp->next;
	}
	update_jobs(jobs->process);
	if (terminate_process(jobs->process))
		reset_process(jobs);
	else
	{
		print_status(jobs->process, jobs->index);
		modify_runing(jobs->process, false);
		modify_foreground(jobs->process, false);
	}
}

void		close_fildes(t_process *process)
{
	while (process)
	{
		close_pipe(process->fildes);
		process = process->next;
	}
}

void		my_wait(t_jobs *jobs)
{
	t_process *process;

	if (jobs)
	{
		while (jobs->process->prev)
			jobs->process = jobs->process->prev;
		close_fildes(jobs->process);
		if (jobs->process)
		{
			if (jobs->process->foreground)
			{
				set_fildes(jobs->process->pgid);
				wait_process(jobs);
				set_fildes(getpgid(0));
				pjt(jobs);
			}
			else
			{
				print_info_jobs(jobs);
				process = jobs->process;
				while (process)
				{
					log_error("Wait [%d]", waitpid(process->pid, &process->status, WNOHANG));
					process = process->next;
				}
				pjt(jobs);
			}
		}
	}
}