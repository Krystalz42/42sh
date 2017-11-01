//
// Created by Alexandre ROULIN on 10/31/17.
//

#include <sh.h>



t_process			*new_process(t_jobs *jobs)
{
	t_process			*temp;

	if (jobs->process == NULL)
	{
		jobs->process = (t_process *)ft_memalloc(sizeof(t_process));
		return (jobs->process);
	}
	else
	{
		temp = jobs->process;
		while (temp->next)
			temp = temp->next;
		temp->next = (t_process *)ft_memalloc(sizeof(t_process));
		temp->next->prev = temp;
		return (temp->next);
	}
}


t_process			*my_fork(t_jobs *jobs, t_node *node, int info)
{
	t_process		*process;

	process = new_process(jobs);
	if ((process->pid = fork()) == -1)
		error_builtin("fork :", "fork failed", NULL);
	process->running = true;
	process->command = ft_strdup(node->content->input);
log_debug("%s setpgid(%d, %d)", process->pid ? "Daddy" : "Fiston", process->pid, process->prev ? process->prev->pgid : process->pid);
	setpgid(process->pid, process->prev ? process->prev->pgid : process->pid);

	process->pgid = getpgid(process->pid);
	process->status = -1;
	process->foreground = (info & FOREGROUND) ? true : false;
	return (process);
}