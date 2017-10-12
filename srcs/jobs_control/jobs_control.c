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

void		update_status(t_process *identify)
{
	if (!identify)
		return ;
	if (WIFEXITED(identify->status))
	{
		pj(*identify, 42, "EXITED");
		var_return(WEXITSTATUS(identify->status));
		reset_process(identify);
	}
	else if (WIFSIGNALED(identify->status))
	{
		pj(*identify, 42, "SIGNALED");
		var_return(WTERMSIG(identify->status) + 128);
		reset_process(identify);
		kill(-identify->pgid, SIGPIPE);
	}
	else if (WIFCONTINUED(identify->status))
	{
		log_info("Continued [%d]", identify->pid);
		identify->running = true;
	}
	else if (WIFSTOPPED(identify->status))
	{
		log_info("Stopped [%d] id [%d]", identify->pid,
				WSTOPSIG(identify->status));
		identify->running = false;
		identify->foreground = false;
		var_return(WSTOPSIG(identify->status) + 128);
	}
	else
	{
		log_fatal("There is probleme");
		reset_process(identify);
	}
	pj(*identify, 42, "UPDATE STATUS");
}

static void		send_signal(t_jobs *jobs, t_jobs jobs_id, int sig)
{
	int index;

	index = MAX_CHILD;
	log_error("SIGNAL_RECEPTION [%d] [%d]", sig, jobs_id.father.pid);
	if (jobs_id.father.pid != -1)
		index = jobs_id.father.pid;
	else
		while (index >= 0 && !(jobs[index].father.pid
					&& jobs[index].father.foreground))
			index--;
	if (index != -1)
	{
		pj(jobs[index].father, index, "KILL SEND");
		kill(-jobs[index].father.pgid, sig);
	}
	else if (sig == SIGINT)
	{
		log_info("Send KEY_INTERRUPT to shell");
		ioctl(0, TIOCSTI, "\2\0");
	}
	else if (sig == SIGWINCH)
	{
		ioctl(0, TIOCSTI, "\28\0");
	}
	else
	{
		log_warn("Signal nothing done ! ");
		bip();
	}
}

void		full_update(t_jobs *jobs)
{
	int			index;
	int			index_child;
	pid_t		test;

	log_error("[SIGCHLD] Update.. ");
	index = MAX_CHILD;
	while (--index >= 0)
		if (jobs[index].father.pid)
		{
			index_child = MAX_CHILD;
			while (--index_child >= 0)
				if (jobs[index].child[index_child].pid)
				{
					pj(jobs[index].child[index_child],
					index_child, "FULL UPDATE");
					if ((test = waitpid(jobs[index].child[index_child].pid,
									&(jobs[index].child[index_child].status),
									WUNTRACED | WNOHANG | WCONTINUED)) != -1)
					{
						log_info("Updating [%d] Return [%d]",
								jobs[index].child[index_child].pid, test);
						update_status(&(jobs[index].child[index_child]));
					}
				}
		}
}

t_process		*looking_for(t_jobs *jobs, t_process id)
{
	int			index;

	log_error("Update a parent ..");
	index = MAX_CHILD;
	while (--index >= 0)
		if (jobs[index].father.pid == id.pid)
		{
			jobs[index].father.status = id.status;
			pj(jobs[index].father, index, "Update in parent");
			return (&(jobs[index].father));
		}
	return (NULL);
}

int		jobs_control(unsigned int flags, t_jobs jobs_id, int sig)
{
	static t_jobs			jobs[MAX_CHILD + 1];

	if ((flags & NEW_CHILD))
		return (add_new_child(jobs, jobs_id));
	else if ((flags & SIGNAL_RECEPTION))
		send_signal(jobs, jobs_id, sig);
	else if ((flags & SIGNAL_SIGCHLD))
		full_update(jobs);
	else if ((flags & UPDATE_CHILD))
		update_status(looking_for(jobs, jobs_id.father));
	else if ((flags & FOREGROUND))
		put_in_foreground(jobs, jobs_id);
	else if ((flags & BACKGROUND))
		put_in_background(jobs, jobs_id);
	else if ((flags & PRINT_JOBS))
		print_jobs(jobs, sig);
	return (-1);
}