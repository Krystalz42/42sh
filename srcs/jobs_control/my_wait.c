/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_wait.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 16:40:09 by jle-quel          #+#    #+#             */
/*   Updated: 2017/11/17 16:41:23 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

int				wait_group(t_process *process, int option)
{
	int			ret;

	ret = 0;
	while (process)
	{
		if ((waitpid(process->pid, &process->status, option)) > 0)
			ret = 1;
		process = process->next;
	}
	return (ret);
}

void			set_fildes(pid_t pgid)
{
	signal(SIGTTIN, SIG_IGN);
	signal(SIGTTOU, SIG_IGN);
	tcsetpgrp(STDIN_FILENO, pgid);
}

void			wait_process(t_jobs *jobs)
{
	wait_group(jobs->process, WUNTRACED);
	update_jobs(jobs->process);
	if (terminate_process(jobs->process))
		reset_process(jobs);
	else
	{
		print_status(jobs->process, jobs->index);
		modify_runing(jobs->process, false);
		modify_foreground(jobs->process, false);
	}
}

void			my_wait(t_jobs *jobs)
{
	if (jobs)
	{
		first_process(jobs);
		close_fildes(jobs->process);
		if (jobs->process)
		{
			if (jobs->process->foreground)
			{
				set_fildes(jobs->process->pgid);
				wait_process(jobs);
				set_fildes(getpgid(0));
			}
			else
			{
				wait_group(jobs->process, WNOHANG);
				print_info_jobs(jobs);
			}
		}
	}
}
