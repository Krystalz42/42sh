#include <sh.h>

void					intro_heredoc(t_jobs *jobs)
{
	t_process		*process;

	if ((process = get_process(jobs->process, getpid())))
	{
		process->fdout = dup(STDOUT_FILENO);
		dup2(process->fildes[1], process->fdout);
	}

}

uint8_t					op_dless(t_node *node, t_jobs *jobs, int info)
{
	int			fildes[2];

	log_debug("VALUE_DLESS %d", info);
	if (info & FORK)
	{
		pipe(fildes);
		if ((jobs = new_jobs(jobs)) == NULL)
			return (var_return(255));
		jobs->process = my_fork(jobs, node, info);
		jobs->process->fildes[0] = fildes[0];
		jobs->process->fildes[1] = fildes[1];
		jobs->process->fdout = dup(STDOUT_FILENO);
		if (jobs->process->pid > 0)
		{
			my_wait(jobs);
		}
		else
		{
			jobs->process->pid = getpid();
			intro_heredoc(jobs);
			ft_putstrtab_fd(node->right->content->heredoc, 10, jobs->process->fdout);
			execute_node(node->left, jobs, (info | READ) ^ FORK);
		}
	}
	else
	{
		if (jobs->process->fdout == -1)
			intro_heredoc(jobs);
		ft_putstrtab_fd(node->right->content->heredoc, 10, jobs->process->fdout);
		execute_node(node->left, jobs, info);
	}
	return (1);
}
