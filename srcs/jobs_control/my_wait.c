/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_wait.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 16:40:09 by jle-quel          #+#    #+#             */
/*   Updated: 2017/11/19 11:56:25 by sbelazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

t_process		*place_status(pid_t pid, int status)
{
	t_process		*process;

	if ((process = get_process(pid)) != NULL)
		process->status = status;
	return (process);
}

int				wait_group(t_process *process, int option)
{
	pid_t		pid;
	int			status;

	while (process)
	{
		if ((pid = waitpid(-process->pgid, &status, option)) > 0)
			place_status(pid, status);
		process = process->next;
	}
	return (0);
}

void			set_fildes(pid_t pgid)
{
	signal(SIGTTIN, SIG_IGN);
	signal(SIGTTOU, SIG_IGN);
	tcsetpgrp(STDIN_FILENO, pgid);
	signal(SIGTTIN, SIG_DFL);
	signal(SIGTTOU, SIG_DFL);
}

void			my_wait(t_jobs *jobs)
{
	log_fatal("Adress of {jobs} in Wait [%p]", jobs);
	close_fildes(jobs->process);
	if (jobs->process->foreground)
	{
		set_fildes(jobs->process->pgid);
		wait_group(jobs->process, WUNTRACED);
		set_fildes(getpgid(0));
		update_status(jobs->process);
		if (finished_process(jobs->process))
			memdel_jobs(jobs);
		else
		{
			modify_foreground(jobs->process, false);
			modify_runing(jobs->process, false);
			print_status(jobs->process, jobs->index);
		}
	}
	else
	{
		print_info_jobs(jobs->process, jobs->index);
	}
}
