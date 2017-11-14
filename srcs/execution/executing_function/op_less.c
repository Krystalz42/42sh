//
// Created by Alexandre ROULIN on 11/2/17.
//

#include <sh.h>

static void			jobs_op_less(t_node *node)
{
	int		fildes;

	fildes = open(node->right->content->command[0], O_RDONLY);
	dup2(fildes, STDIN_FILENO);
	close(fildes);
}

uint8_t			op_less(t_node *node, t_jobs *jobs, int info)
{
	log_debug("VALUE_LESS %d", info);
	if (info & FORK)
	{
		if ((jobs = new_jobs(jobs)) == NULL)
			return (var_return(255));
		jobs->process = my_fork(jobs, find_executing_node(node), info);
		if (jobs->process->pid > 0)
		{
			my_wait(jobs);
		}
		else
		{
			jobs->process->pid = getpid();
			jobs_op_less(node);
			execute_node(node->left, jobs, info ^ FORK);
		}
	}
	else
	{
		jobs_op_less(node);
		execute_node(node->left, jobs, info);
	}
	return (var_return(-1));
}
