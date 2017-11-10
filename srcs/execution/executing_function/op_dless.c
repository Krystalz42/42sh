#include <sh.h>


uint8_t					op_dless(t_node *node, t_jobs *jobs, int info)
{
	int			fildes[2];
	int			fd;

	log_debug("VALUE_DLESS %d", info);
	if (info & FORK)
	{
		pipe(fildes);
		if ((jobs = new_jobs(jobs)) == NULL)
			return (var_return(255));
		jobs->process = my_fork(jobs, node, info);
		jobs->process->fildes[0] = fildes[0];
		fd = dup(STDOUT_FILENO);
		jobs->process->fildes[1] = fd;
		if (jobs->process->pid > 0)
		{
			close_previous(jobs);
			close(fildes[0]);
			dup2(fildes[1], fd);
			close(fildes[1]);
			ft_putstrtab_fd(node->right->content->command, 10, fd);
			close(fd);
			my_wait(jobs);
		}
		else
		{

			read_pipe(fildes);
			execute_node(node->left, jobs, info ^ FORK);
		}
	}
	else
	{
		ft_putstrtab_fd(node->right->content->command, 10, jobs->process->fildes[1]);
		execute_node(node->left, jobs, info);
	}
	return (1);
}
