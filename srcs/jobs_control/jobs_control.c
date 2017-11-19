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

	while ((pid = waitpid(-1, &status, 0)) != -1)
		if ((jobs = get_jobs(place_status(pid, status)->pgid)) != NULL)
		{
			wait_group(jobs->process, WNOHANG | WUNTRACED);
			update_status(jobs->process);
			if (finished_process(jobs->process))
			{
				update_jobs(jobs->process);
				memdel_jobs(jobs);
			}
			else
			{
				modify_foreground(jobs->process, false);
				modify_runing(jobs->process, false);
				print_status(jobs->process, jobs->index);
			}
		}
}



void				handler_sigchld(int sig)
{
	log_trace("/!\\  [SIGCHLD RECEPTION %d] /!\\", sig);
	check_child_in_background();
}
