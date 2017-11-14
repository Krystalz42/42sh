/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jobs_control.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 19:09:46 by aroulin           #+#    #+#             */
/*   Updated: 2017/10/11 19:09:48 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

t_jobs				*jobs_table(void)
{
	static t_jobs		jobs[MAX_CHILD];

	return (jobs);
}

void			update_jobs(t_process *process)
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

int			place_status(t_process *process, pid_t pid, int status)
{
	while (process->prev)
		process = process->prev;
	while (process)
	{
		if (process->pid == pid)
		{
			log_fatal("Find it !");
			process->status = status;
			return (1);
		}
		process = process->next;
	}
	return (0);
}

t_jobs				*update_status_jobs(pid_t pid, int status)
{
	t_jobs			*jobs;
	int				index;

	jobs = jobs_table();
	index = 0;
	while (index < MAX_CHILD)
	{
		if (jobs[index].process)
		{
			if (place_status(jobs[index].process, pid, status))
			{
				log_success("%d", jobs[index].process->pgid);
				return (jobs + index);
			}
		}
		index++;
	}
	return (NULL);
}

void				handler_sigchld(int sig)
{
	t_jobs		*jobs;
	int			status;
	int			pid;

	(void)sig;
	log_trace("/!\\  [SIGCHLD RECEPTION %d] /!\\", sig);
	pid = waitpid(-1, &status, WUNTRACED);
	if ((jobs = update_status_jobs(pid, status)))
		if (jobs->process->foreground == false)
		{
			if (finish_process(jobs->process))
			{
				print_status(jobs->process, jobs->index);
				reset_process(jobs);
			}
			else
			{
				print_status(jobs->process, jobs->index);
				modify_runing(jobs->process, false);
				modify_foreground(jobs->process, false);
			}
		}
}