//
// Created by Alexandre ROULIN on 10/31/17.
//

#include <sh.h>

static void					play_with_fildes(t_jobs *jobs, int info)
{
	t_process		*process;

	if ((process = get_process(jobs->process, getpid())))
	{
		if (WRITE_PREVIOUS & info)
		{
			log_trace("Write %d", getpid());
			if (process->prev)
				write_pipe(process->prev->fildes);
		}
		if (READ & info)
		{
			log_trace("Read %d", getpid());
			read_pipe(process->fildes);
		}
		close_pipe(process->fildes);
	}

}

static void				do_execution(t_node *node, t_jobs *jobs, int info)
{
	log_debug("VALUE_EXECUTION %d", info);
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
			play_with_fildes(jobs, info);
			my_execve(node->content->command, get_real_env(node));
		}
	}
	else
	{
		play_with_fildes(jobs, info);
		my_execve(node->content->command, get_real_env(node));
	}
}

uint8_t					op_execution(t_node *node, t_jobs *jobs, int info)
{
	if (check_if_builtin(node, info) >= 0)
	{
		if (!(info & FORK))
			exit(var_return(-1));
	}
	else
		do_execution(node, jobs, info);
	return (var_return(-1));
}

