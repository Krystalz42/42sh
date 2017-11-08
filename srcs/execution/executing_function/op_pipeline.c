//

#include <sh.h>



uint8_t			op_pipeline(t_node *node, t_jobs *jobs, int info)
{
	int				fildes[2];

	log_debug("VALUE PIPELINE %d", info);

	if ((jobs = new_jobs(jobs)) == NULL)
		return (var_return(255));
	pipe(fildes);
	jobs->process = my_fork(jobs, node, info);
	jobs->process->fildes[0] = fildes[0];
	jobs->process->fildes[1] = fildes[1];
	if (jobs->process->pid > 0) // PAPA
	{
		log_info("Do left");
		close_previous(jobs);
		execute_node(node->left, jobs, info | WRITE);
	}
	else // FILS
	{
		log_info("Do right");
		write_previous(jobs);
		execute_node(node->right, jobs, info ^ FORK);
	}
	return (1);
}