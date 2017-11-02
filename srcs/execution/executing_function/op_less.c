//
// Created by Alexandre ROULIN on 11/2/17.
//

#include <sh.h>

uint8_t			op_less(t_node *node, int info)
{
	int		fildes_read;
	int		fildes_file;
	t_jobs	*jobs;

	fildes_read = ft_atoi(node->content->input);
	fildes_file = open(node->right->content->command[0], O_RDONLY);
	if ((jobs = new_jobs()) == NULL)
		return (var_return(255));
	jobs->process = my_fork(jobs, node, info);
	if (jobs->process->pid > 0)
		my_wait(jobs);
	else
	{
		log_debug("dup2(%d, %d)", fildes_file, fildes_read);
		dup2(fildes_file, fildes_read);
		close(fildes_file);
		execute_node(node->left, (info & FORK) ? info - FORK : info);
	}
	return (var_return(-1));
}
