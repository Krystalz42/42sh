//
// Created by Alexandre ROULIN on 11/12/17.
//

#include <sh.h>


void		jobs_op_great_and(t_node *node)
{
	int			fildes;

	log_error("%s",node->right->content->command[0]);
	if (node->right->content->command[0][0] == '-')
		fildes = open(PATH_ERROR, O_WRONLY);
	else if (ft_strisdigit(node->right->content->command[0]))
		fildes = ft_atoi(node->right->content->command[0]);
	else
		fildes = open(node->right->content->command[0], OPTION_GREAT, 0644);
	log_error("%d", fildes);
	if (ft_isdigit(node->content->command[0][0]))
	{
		log_warn("From %d to %d", ft_atoi(node->content->command[0]),fildes );
		dup2(fildes, ft_atoi(node->content->command[0]));
	}
	else
	{
		log_warn("From %d to %d", fildes, 1);
		dup2(fildes, STDOUT_FILENO);
	}
	close(fildes);
}

uint8_t					op_great_and(t_node *node, t_jobs *jobs, int info)
{
	log_debug("VALUE GREAT_AND %d", info);

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
			jobs_op_great_and(node);
			execute_node(node->left, jobs, (info ^ FORK));
		}
	}
	else
	{
		jobs_op_great_and(node);
		execute_node(node->left, jobs, info);
	}
	return (var_return(-1));
}
