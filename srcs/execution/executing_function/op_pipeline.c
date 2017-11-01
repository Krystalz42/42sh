//

#include <sh.h>



uint8_t			pipeline(t_node *node, int info, t_jobs *jobs, int *fildes)
{
	int				fildes_s[2];
	t_process		*process;

	(node->content->value == VALUE_PIPELINE) && pipe(fildes_s);
	process = my_fork(jobs, node, info);
	if (process->pid > 0 && close_pipe(fildes))
	{
		node->content->value != VALUE_PIPELINE ? my_wait(jobs) : 0;
		if (node->content->value == VALUE_PIPELINE)
			pipeline(node->left, info, jobs, fildes_s);
	}
	else
	{
		if (node->content->value == VALUE_PIPELINE)
		{
			write_pipe(fildes) && read_pipe(fildes_s);
			op_execution(node->right, info - FORK);
		}
		else
		{
			write_pipe(fildes);
			op_execution(node, info - FORK);
		}
	}
	return (1);
}

uint8_t			op_pipeline(t_node *node, int info)
{
	t_jobs			*jobs;

	if ((jobs = new_jobs()) == NULL)
		return (var_return(255));
	return (pipeline(node, info, jobs, NULL));
}