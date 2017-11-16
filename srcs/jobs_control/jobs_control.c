/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jobs_control.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <aroulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 19:09:46 by aroulin           #+#    #+#             */
/*   Updated: 2017/11/16 16:20:05 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

t_jobs				*jobs_table(void)
{
	static t_jobs		jobs[MAX_CHILD];

	return (jobs);
}

void				update_jobs(t_process *process)
{
	log_trace("/!\\  [PROCESS LL BE UPDATE] /!\\");
	while (process)
	{
		if (process->pid == process->pgid)
		{
			if (WIFEXITED(process->status))
				var_return(WEXITSTATUS(process->status));
			else if (WIFSIGNALED(process->status))
				var_return(WTERMSIG(process->status) + 128);
			else if (WIFSTOPPED(process->status))
				var_return(WSTOPSIG(process->status) + 128);
			else if (WIFCONTINUED(process->status))
				;
		}
		process = process->next;
	}
}

void				handler_sigchld(int sig)
{
	t_jobs		*jobs;
	int			index;

	log_trace("/!\\  [SIGCHLD RECEPTION %d] /!\\", sig);
	jobs = jobs_table();
	index = 0;
	(void)sig;
	while (index < MAX_CHILD)
	{
		if (jobs[index].process && jobs[index].process->foreground == false)
			if (wait_group(jobs[index].process, WNOHANG))
			{
				if (terminate_process(jobs[index].process))
				{
					update_jobs(jobs[index].process);
					print_status(jobs[index].process, jobs[index].index);
					reset_process(jobs);
				}
				else if (finish_process(jobs[index].process))
				{
					print_status(jobs[index].process, jobs[index].index);
				}
			}
		index++;
	}
}
