/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jobs_control.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <aroulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 19:09:46 by aroulin           #+#    #+#             */
/*   Updated: 2017/11/19 11:57:30 by sbelazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

t_jobs				*jobs_table(t_jobs *jobs, unsigned int flags)
{
	static t_jobs		*save;

	if (flags & RESET_STRUCT)
		save = NULL;
	else if (flags & SAVE_STRUCT)
		save = jobs;
	else if (REC_STRUCT)
		return (save);
	return (NULL);
}

void				update_jobs(t_process *process)
{
	while (process)
	{
		if (process->pgid == process->pid && process->status != -1)
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

void				check_child_in_background(void)
{
	t_jobs		*jobs;
	int			pid;
	int			status;
	t_process	*process;

	while ((pid = waitpid(WAIT_ANY, &status, WNOHANG)) > 0)
		if ((process = place_status(pid, status)))
			if ((jobs = get_jobs(process->pgid)) != NULL)
			{
				dprintf(fd_log, "jobs %d\n", jobs ? 1 : 0);
				wait_group(jobs->process, WNOHANG);
				update_status(jobs->process);
				update_jobs(jobs->process);
				ft_dprintf(fd_log, "finished process [%d]\n",finished_process(jobs->process));
				if (finished_process(jobs->process))
				{
					print_status(jobs, jobs->process);
					memdel_jobs(jobs);
				}
				else
				{
					modify_foreground(jobs->process, false);
					modify_runing(jobs->process, false);
				}
			}
}

void				handler_sigchld(int sig)
{
	(void)sig;
	check_child_in_background();
}
