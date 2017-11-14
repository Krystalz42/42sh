//
// Created by Alexandre ROULIN on 10/6/17.
//

#include <sh.h>

void			place_status(t_process *process, pid_t pid, int status)
{
	while (process->prev)
		process = process->prev;
	while (process)
	{
		if (process->pid == pid)
		{
			log_fatal("dsa");
			process->status = status;
		}
		process = process->next;
	}
}

int			wait_group(t_process *process, int option)
{
	pid_t		pid;
	int			status;
	int			ret;

	ret = 0;
	while ((pid = waitpid(-process->pgid, &status, option)) != -1)
	{
		sleep(1);
		log_fatal("%d", pid);
		place_status(process, pid, status);
		log_fatal("%d %d %d", process->pid, process->status, status);
		ret = 1;
	}
	return (ret);
}

void			set_fildes(pid_t pgid)
{
	signal(SIGTTIN, SIG_IGN);
	signal(SIGTTOU, SIG_IGN);
	log_trace("FG Return tcsetpgrp(0, %d) == [%d]", pgid, tcsetpgrp(STDIN_FILENO, pgid));
}
void			wait_process(t_jobs *jobs)
{
	wait_group(jobs->process, WUNTRACED | WCONTINUED);
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
				pjt(jobs);
				set_fildes(jobs->process->pgid);
				wait_process(jobs);
				set_fildes(getpgid(0));
				pjt(jobs);
			}
			else
			{
				print_info_jobs(jobs);
			}
		}
	}
}