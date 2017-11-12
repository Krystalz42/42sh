#include <sh.h>

void					intro_heredoc(t_node *node, t_jobs *jobs)
{
	t_process		*process;
	int				fildes;

	fildes = open(node->content->heredoc, O_RDONLY);
	if ((process = get_process(jobs->process, getpid())))
	{
		if (process->fildes[0] != -1)
		{
			dup2(fildes, process->fildes[0]);
			close(fildes);
		}
		else
		{
			dup2(fildes, STDIN_FILENO);
			close(fildes);
		}
	}
	remove(node->content->heredoc);
}

uint8_t					op_dless(t_node *node, t_jobs *jobs, int info)
{
	log_debug("VALUE_DLESS %d", info);
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
			jobs->process->pid = getpid();
			intro_heredoc(node, jobs);
			execute_node(node->left, jobs, info ^ FORK);
		}
	}
	else
	{
		intro_heredoc(node, jobs);
		execute_node(node->left, jobs, info);
	}
	return (1);
}
