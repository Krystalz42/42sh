//
// Created by Alexandre ROULIN on 10/31/17.
//

#include <sh.h>
void					play_with_fildes(t_jobs *jobs, int info, pid_t pid)
{
	t_process		*process;

	if (jobs)
		if ((process = get_process(jobs->process, pid)))
		{
			if (WRITE_PREVIOUS & info)
			{
				log_trace("Write %d", pid);
				write_pipe(process->prev->fildes);
				close_pipe(process->prev->fildes);
			}
			if (READ & info)
			{
				log_trace("Read %d", pid);
				read_pipe(process->fildes);
				close_pipe(process->fildes);
			}
			close_pipe(process->fildes);
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
	t_process		*process;

	if (FORK & info)
	{
		if ((jobs = new_jobs(jobs)) == NULL)
			return ;
		process = my_fork(jobs, node, info);
		if (process->pid > 0) // father
		{
			log_success("On va wait les enfants!");
			my_wait(jobs);
		}
		else if (process->pid == 0) // fils
		{
			process->pid = getpid();
			if (process->prev)
				write_pipe(process->prev->fildes);
			jobs_execution(node, info);
		}
	}
	else
	{
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

