//
// Created by Alexandre ROULIN on 11/2/17.
//

#include <sh.h>

static int 				compare_heredoc(t_cmd *cmd, char *string)
{
	int			index;

	index = 0;
	while (cmd->c && string[index])
	{
		if (cmd->c != string[index])
			break ;
		cmd = cmd->next;
		index++;
	}
	return (cmd->c - string[index]);
}

uint8_t					op_dless(t_node *node, int info)
{
	t_jobs		*jobs;
	int			fildes;

	if ((jobs = new_jobs()) == NULL)
		return (var_return(255));
	jobs->process = my_fork(jobs, node, info);
	if (jobs->process->pid > 0)
	{
		while ((waitpid(jobs->process->pid, &jobs->process->status, WNOHANG)) == -1)
			;
		my_wait(jobs);
	}
	else
	{
		execute_node(node->left, (info & FORK) ? info - FORK : info);
	}
	return (1);
}
