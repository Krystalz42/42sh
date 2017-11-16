//
// Created by Alexandre ROULIN on 11/12/17.
//

#include <sh.h>

static int	check_fd(int fildes)
{
	if (fildes == init_fd())
		fildes = STDOUT_FILENO;
	if (fcntl(F_GETFD, fildes) == -1)
	{
		error_msg(S42H, BAD_FD, NULL);
		exit(1);
	}
	return (fildes);
}

void		jobs_op_great_and(t_node *node)
{
	int			fildes;

	if (node->right->content->command[0][0] == '-')
		fildes = open(PATH_ERROR, O_WRONLY);
	else if (ft_strisdigit(node->right->content->command[0]))
		fildes = ft_atoi(node->right->content->command[0]);
	else
		fildes = open(node->right->content->command[0], OPTION_GREAT, 0644);
	fildes = check_fd(fildes);
	if (ft_isdigit(node->content->command[0][0]))
		dup2(fildes, ft_atoi(node->content->command[0]));
	else
		dup2(fildes, STDOUT_FILENO);
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
