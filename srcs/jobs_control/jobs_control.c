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

int 		getindex(t_jobs *jobs, pid_t find)
{
	int			index;

	index = MAX_CHILD;
	while (index >= 0)
	{
		if (jobs[index].father.pid == find)
			return (index);
		index--;
	}
	return (-1);
}

void		print_info(t_process identify, uint8_t info)
{
	int			index;

	(void)info;
	index = jobs_control(GET_INDEX, new_jobs(-1), identify.pid);
	if (identify.foreground == false)
	{
	}
}

void		update_status(t_process *identify)
{
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
	}
	else if (WIFCONTINUED(identify->status))
	{
		log_info("Continued [%d]", identify->pid);
		identify->running = true;
	}
	else if (WIFSTOPPED(identify->status))
	{
		log_info("Stopped [%d] id [%d]", identify->pid, WSTOPSIG(identify->status));
		identify->running = false;
		identify->foreground = false;
		var_return(WSTOPSIG(identify->status) + 128);
	}
	pj(*identify, 42, "UPDATE STATUS");
}

static void		send_signal(t_jobs *jobs, t_jobs jobs_id, int sig)
{
	int index;
	char send[] ={sig,0};


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
		ioctl(0, TIOCSTI, send);
		signal_reception(var_return(131));
	}
	else
	{
		log_warn("Signal nothing done ! ");
	}
}

void		update_process(t_jobs *jobs)
{
	int		index_child;

	log_error("Update process %d", jobs->father.pid);
	pjt(*jobs, 42);
	update_status(&(jobs->father));
	index_child = 0;
	while (jobs->child[index_child].pid)
	{
		pj(jobs->child[index_child], index_child, "FULL UPDATE");
		if ((waitpid((*jobs).child[index_child].pid, &(jobs->child[index_child].status), WUNTRACED | WNOHANG | WCONTINUED)) != -1)
		{
			log_info("Updating [%d]", jobs->child[index_child].pid);
			update_status(&((*jobs).child[index_child]));
		}
		index_child++;
	}

}

void		full_update(t_jobs *jobs)
{
	int			index;

	log_error("[SIGCHLD] Update.. ");
	index = MAX_CHILD;
	while (index >= 0)
	{
		if (jobs[index].father.pid && jobs[index].father.foreground == false)
		{
			log_trace("Find in SIGCHILD %d", index);
			update_process(&(jobs[index]));
		}
		index--;
	}
}

void		update_special(t_jobs *jobs, t_process id, int option)
{
	int			index;


	log_error("Update a parent .. %d", id.pid);
	index = MAX_CHILD;
	while (--index >= 0)
		if (jobs[index].father.pid == id.pid)
		{
			if ((waitpid(jobs[index].father.pid, &(jobs[index].father.status), option)) != -1)
			{
				pj(jobs[index].father, index, "Update special");
				update_process(&(jobs[index]));
			}
		}
	signal(SIGTTOU, SIG_IGN);
	signal(SIGTTIN, SIG_IGN);
	log_trace("Return tsetpgrp(%d) of (%d)", tcsetpgrp(init_fd(), getpgid(0)), getpgid(0));
	init_signal();
}

t_jobs		*jobs_control(unsigned int flags, t_jobs jobs_id, int sig)
{
	static t_jobs			jobs[MAX_CHILD + 1];

	
	if ((flags & NEW_CHILD))
		return (add_new_child(jobs, jobs_id));
	else if ((flags & SIGNAL_RECEPTION))
		send_signal(jobs, jobs_id, sig);
	else if ((flags & SIGNAL_SIGCHLD))
		full_update(jobs);
	else if ((flags & UPDATE_CHILD))
		update_special(jobs, jobs_id.father, sig);
	else if ((flags & FOREGROUND))
		put_in_foreground(jobs, sig);
	else if ((flags & BACKGROUND))
		put_in_background(jobs, sig);
	else if ((flags & PRINT_JOBS))
		return (print_jobs(jobs, sig));
	else if ((flags & GET_INDEX))
		return (getindex(jobs, sig));
	return (-1);
}