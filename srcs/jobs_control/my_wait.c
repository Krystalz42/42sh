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

void		my_wait(int index)
{
	t_jobs		*jobs;
	int			status;
	pid_t		child;

	jobs = jobs_table();
	if (jobs[index].process->foreground)
	{
		log_trace("FG Return tcsetpgrp (%d)  of (%d)", tcsetpgrp(init_fd(), jobs[index].process->pgid), jobs[index].process->pgid);
		if ((child = waitpid(-jobs[index].process[0].pgid, &status, WUNTRACED | WCONTINUED))> 0)
			update_unique_status(jobs[index].process, status, child);
		signal(SIGTTIN, SIG_IGN);
		signal(SIGTTOU, SIG_IGN);
		log_trace("Return tcsetpgrp (%d)  of (%d)", tcsetpgrp(init_fd(), getpgid(0)), getpgid(0));
		update_status(jobs[index].process);
		if (terminate_process(jobs[index].process))
			reset_process(jobs[index].process);
	}
	else
	{
		print_info_jobs(jobs[index], index);
		log_trace("BG Return tcsetpgrp (%d)  of (%d)", tcsetpgrp(init_fd(), jobs[index].process->pgid), jobs[index].process->pgid);
		signal(SIGTTIN, SIG_IGN);
		signal(SIGTTOU, SIG_IGN);
		log_trace("Return tcsetpgrp (%d)  of (%d)", tcsetpgrp(init_fd(), getpgid(0)), getpgid(0));
	}
}