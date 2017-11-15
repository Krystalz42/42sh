//

#include <sh.h>

uint8_t			op_pipeline(t_node *node, t_jobs *jobs, int info)
{
	int				fildes[2];
	t_process		*process;

	log_debug("VALUE PIPELINE %d", info);
	if ((jobs = new_jobs(jobs)) == NULL)
		return (var_return(255));
	pipe(fildes);
	log_debug("[%d][%d]", fildes[0], fildes[1]);
	process = my_fork(jobs, find_executing_node(node), info);
	process->fildes[0] = fildes[0];
	process->fildes[1] = fildes[1];
	if (process->pid > 0)
		execute_node(node->left, jobs, info | FORCE_FORK);
	else
	{
		process->pid = getpid();
		read_pipe(fildes);
		if (process->prev)
			write_pipe(process->prev->fildes);
		execute_node(node->right, jobs, info ^ FORK);
	}
	return (1);
}
