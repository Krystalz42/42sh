//
// Created by Alexandre ROULIN on 10/31/17.
//

#include <sh.h>

static void					play_with_fildes(t_jobs *jobs, int info, pid_t pid)
{
	t_process		*process;

	if (jobs)
		if ((process = get_process(jobs->process, pid)))
		{
			if (WRITE_PREVIOUS & info)
			{
				log_trace("Write %d", pid);
				if (pid == -1)
					write_pipe(process->fildes);
				else if (process->prev)
					write_pipe(process->prev->fildes);
			}
			if (READ & info)
			{
				log_trace("Read %d", pid);
				read_pipe(process->fildes);
			}
			if (pid != -1)
				close_pipe(process->fildes);
			close(jobs->process->fdout);
		}

}

static void				jobs_execution(t_node *node, int info)
{
	if (check_if_builtin(node, info) >= 0)
		exit(var_return(-1));
	else
		my_execve(node->content->command, get_real_env(node));
}

static void				do_execution(t_node *node, t_jobs *jobs, int info)
{
	if (FORK & info)
	{
		if ((jobs = new_jobs(jobs)) == NULL)
			return ;
		jobs->process = my_fork(jobs, node, info);
		if (jobs->process->pid > 0) // father
		{
			my_wait(jobs);
		}
		else if (jobs->process->pid == 0) // fils
		{
			jobs->process->pid = getpid();
			play_with_fildes(jobs, info, getpid());
			jobs_execution(node, info);
		}
	}
	else
	{
		play_with_fildes(jobs, info, getpid());
		jobs_execution(node, info);
	}
}

uint8_t					op_execution(t_node *node, t_jobs *jobs, int info)
{
	log_debug("VALUE_EXECUTION %d", info);
	if (check_if_builtin(node, info | DONT_EXECUTE) >= 0 &&
			!(info & FORCE_FORK) && (info & FORK))
		check_if_builtin(node, info);
	else
		do_execution(node, jobs, info);
	return (var_return(-1));
}

