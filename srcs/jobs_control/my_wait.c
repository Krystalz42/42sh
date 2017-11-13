//
// Created by Alexandre ROULIN on 10/6/17.
//

#include <sh.h>


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
		waitpid(-temp->pgid, &temp->status, WUNTRACED);
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