//
// Created by Alexandre ROULIN on 11/12/17.
//

#include <sh.h>

void		jobs_op_dgreat(t_node *node)
{
	int			fildes;

	fildes = open(node->right->content->command[0], OPTION_DGREAT, 0644);
	if (node->content->command[0][0] == '&')
	{
		dup2(fildes, STDOUT_FILENO);
		dup2(fildes, STDERR_FILENO);
	}
	else if (ft_isdigit(node->content->command[0][0]))
	{
		dup2(fildes, ft_atoi(node->content->command[0]));
	}
	else
	{
		dup2(fildes, STDOUT_FILENO);
	}
	close(fildes);
}

uint8_t					op_dgreat(t_node *node, t_jobs *jobs, int info)
{
	log_debug("VALUE DGREAT %d", info);

	if (info & FORK)
	{
		if ((jobs = new_jobs(jobs)) == NULL)
			return (var_return(255));
		jobs->process = my_fork(jobs, find_executing_node(node), info);
		if (jobs->process->pid)
		{
			my_wait(jobs);
		}
		else
		{
			jobs->process->pid = getpid();
			jobs_op_dgreat(node);
			execute_node(node->left, jobs, info ^ FORK);
		}
	}
	else
	{
		jobs_op_dgreat(node);
		execute_node(node->left, jobs, info);
	}
	return (1);
}
