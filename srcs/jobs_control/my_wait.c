/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_wait.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 16:40:09 by jle-quel          #+#    #+#             */
/*   Updated: 2017/11/19 01:31:45 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

int				wait_group(t_process *process, int option)
{
	int		ret;

	ret = 0;
	if (process)
	{
		while (process)
		{
			if ((waitpid(process->pid, &process->status, option)) > 0)
				ret = 1;
			process = process->next;
		}
	}
	return (ret);
}

void			set_fildes(pid_t pgid)
{
	signal(SIGTTIN, SIG_IGN);
	signal(SIGTTOU, SIG_IGN);
	tcsetpgrp(STDIN_FILENO, pgid);
}

void			wait_process(t_jobs *jobs, int option)
{
	int			ret;

	wait_group(jobs->process, option);
	update_jobs(jobs->process);
	if ((ret = terminate_process(jobs->process)) != 0)
	{
		(ret > 0) ? print_status(jobs->process, jobs->index) : 0;
		reset_process(jobs);
	}
	else if (!(WNOHANG & option))
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
		close_fildes(jobs->process);
		if (jobs->process)
		{
			if (jobs->process->foreground)
			{
				waitpid(-jobs->process->pgid, 0, WUNTRACED);
//				set_fildes(jobs->process->pgid);
//				wait_process(jobs, WUNTRACED);
//				set_fildes(getpgid(0));
			}
			else
			{
				print_info_jobs(jobs);
			}
		}
	}
}
