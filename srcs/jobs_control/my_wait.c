//
// Created by Alexandre ROULIN on 10/6/17.
//

#include <sh.h>



void		print_info_jobs(t_jobs jobs, int index)
{
	int			index_child;

	index_child = 0;
	ft_printf("[%d] ", index + 1);
	while (jobs.process[index_child].pid)
	{
		ft_putnbr(jobs.process[index_child].pid);
		ft_putchar(32);
		index_child++;
	}
	ft_putchar(10);
}

void			set_fidles(pid_t pgid)
{
	signal(SIGTTIN, SIG_IGN);
	signal(SIGTTOU, SIG_IGN);
	log_trace("FG Return tcsetpgrp (%d)  of (%d)", tcsetpgrp(STDIN_FILENO, pgid), pgid);
}
void			wait_process(t_process *process, int index)
{
	int			index_child;

	index_child = 0;
	while (process[index_child].pid)
	{
		log_error("Wait [%d]",waitpid(process[index_child].pid, &process[index_child].status, WUNTRACED));
		index_child++;
	}
	if (terminate_process(process))
	{
		update_jobs(process, index);
		reset_process(process);
	}
	else
	{
		print_status(process, index);
		modify_runing(process, false);
		modify_foreground(process, false);
	}
}

void		my_wait(int index)
{
	t_jobs		*jobs;


	jobs = jobs_table();
	if (jobs[index].process->foreground)
	{
		set_fidles(jobs[index].process->pgid);
		wait_process(jobs[index].process, index);
		pjt(jobs[index], index);
		set_fidles(getpgid(0));
	}
	else
	{
		print_info_jobs(jobs[index], index);
	}
}