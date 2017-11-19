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

t_jobs				**jobs_table(void)
{
	static t_jobs		*jobs;

	return (&jobs);
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

int					wait_chld(t_process *process)
{
	pid_t			pid;
	int				status;

	if ((pid = waitpid(-process->pgid, &status, WNOHANG | WUNTRACED)) > 0)
	{
		place_status(process, pid, status);
		wait_group(process, WUNTRACED | WNOHANG);
		return (1);
	}
	return (0);
}

void				handler_sigchld(int sig)
{
//	t_jobs		*jobs;

	log_trace("/!\\  [SIGCHLD RECEPTION %d] /!\\", sig);
	while (wait(0) != -1)
		;
//	jobs = *jobs_table();
//	(void)sig;
//	while (jobs)
//	{
//		if (jobs->process && jobs->process->foreground == false)
//			if (wait_chld(jobs->process))
//			{
//				if (terminate_process(jobs->process))
//				{
//					update_jobs(jobs->process);
//					print_status(jobs->process, jobs->index);
//					reset_process(jobs);
//				}
//				else if (finish_process(jobs->process))
//				{
//					print_status(jobs->process, jobs->index);
//				}
//			}
//		jobs = jobs->next;
//	}
}
