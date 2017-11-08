//
// Created by Alexandre ROULIN on 10/31/17.
//

#include <sh.h>

void					play_with_fildes(t_jobs *jobs, int info)
{
	if (info & WRITE)
		write_previous(jobs);
	if (info & READ)
		read_previous(jobs);
}

uint8_t					do_execution(t_node *node, t_jobs *jobs, int info)
{
	log_debug("VALUE_EXECUTION %d", info);
	if (FORK & info)
	{
		if ((jobs = new_jobs(jobs)) == NULL)
			return (var_return(255));
		jobs->process = my_fork(jobs, node, info);
		if (jobs->process->pid > 0) // father
		{
			close_previous(jobs);
			my_wait(jobs);
		}
		else if (jobs->process->pid == 0) // fils
		{
			play_with_fildes(jobs, info);
			my_execve(node->content->command, get_real_env(node));
		}
	}
	else
	{
		play_with_fildes(jobs, info);
		my_execve(node->content->command, get_real_env(node));
	}
	return (var_return(-1));
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

