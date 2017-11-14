//
// Created by Alexandre ROULIN on 10/6/17.
//

#include <sh.h>


int			wait_group(t_process *process)
{
	while (finish_process(process) != 1)
		;
	return (1);
}

void			set_fildes(pid_t pgid)
{
	signal(SIGTTIN, SIG_IGN);
	signal(SIGTTOU, SIG_IGN);
	log_trace("FG Return tcsetpgrp(0, %d) == [%d]", pgid, tcsetpgrp(STDIN_FILENO, pgid));
}
void			wait_process(t_jobs *jobs)
{
	wait_group(jobs->process);
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

void		my_wait(t_jobs *jobs)
{
	if (jobs)
	{
		first_process(jobs);
		close_fildes(jobs->process);
		if (jobs->process)
		{
			if (jobs->process->foreground)
			{
				set_fildes(jobs->process->pgid);
				wait_process(jobs);
				set_fildes(getpgid(0));
			}
			else
			{
				print_info_jobs(jobs);
			}
		}
	}
}