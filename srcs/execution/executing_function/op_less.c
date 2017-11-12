//
// Created by Alexandre ROULIN on 11/2/17.
//

#include <sh.h>

uint8_t			op_less(t_node *node, t_jobs *jobs, int info)
{
	int		fildes;
	log_debug("VALUE_LESS %d", info);

	if (info & FORK)
	{
		if ((jobs = new_jobs(jobs)) == NULL)
			return (var_return(255));
		jobs->process = my_fork(jobs, node, info);
		if (jobs->process->pid > 0)
		{
			my_wait(jobs);
		}
		else
		{
			if ((fildes = open(node->right->content->command[0], O_RDONLY)) == -1)
				exit(1);
			jobs->process->pid = getpid();
			dup2(fildes, STDIN_FILENO);
			close(fildes);
			execute_node(node->left, jobs, info ^ FORK);
		}
	}
	else
	{
		if ((fildes = open(node->right->content->command[0], O_RDONLY)) == -1)
			exit(1);
		dup2(fildes, STDIN_FILENO);
		close(fildes);
		execute_node(node->left, jobs, info);
	}
	return (var_return(-1));
}
