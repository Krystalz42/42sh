/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_wait.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 16:40:09 by jle-quel          #+#    #+#             */
/*   Updated: 2017/11/20 15:56:46 by jle-quel         ###   ########.fr       */
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
	while (process)
	{
		dprintf(fd_log, "Return wait [%d]\n", waitpid(process->pid, &process->status, option));
		process = process->next;
	}
	return (0);
}

void			set_fildes(pid_t pgid)
{
	tcsetpgrp(STDIN_FILENO, pgid);
}

void			check_child_in_foreground(t_jobs *jobs)
{
	if (jobs->process && jobs->process->foreground)
	{
		set_fildes(jobs->process->pgid);
		wait_group(jobs->process, WUNTRACED);
		set_fildes(getpgid(0));
		update_status(jobs->process);
		update_jobs(jobs->process);
		if (finished_process(jobs->process))
		{
			memdel_jobs(jobs);
		}
		else
		{
			modify_foreground(jobs->process, false);
			modify_runing(jobs->process, false);
			print_status(jobs, jobs->process);
		}
	}
}

void			my_wait(t_jobs *jobs)
{
	close_fildes(jobs->process);
	add_next_use(jobs);
	if (jobs->process && jobs->process->foreground == 0)
	{
		print_info_jobs(jobs->process, jobs->index);
	}
	else
	{
		check_child_in_foreground(jobs);
	}
}
