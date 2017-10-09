

#include <sh.h>

void pj(t_jobs jobs, int i, char *inc)
{
	log_info("%s PID [%d] PGID [%d] RUNING [%d] FG [%d] PARENT [%d] INDEX [%d]"
	,inc, jobs.pid,jobs.pgid, jobs.running, jobs.foreground, jobs.parent, i);

}

static void		add_new_child(t_jobs *jobs, t_jobs jobs_id)
{
	int			index;

	index = MAX_CHILD;
	while (index >= 0 && !jobs[index].pid)
		index--;
	if (index != MAX_CHILD)
	{
		jobs[index + 1] = jobs_id;
		pj(jobs[index + 1], index +1 , "NEW_CHILD");
	}
}

static void		update_status(t_jobs *jobs, t_jobs jobs_id)
{
	int		index;

	index = MAX_CHILD;
	log_info("Updating ...");
	while (index >= 0)
	{
		if (jobs[index].pid == jobs_id.pid)
		{
			if (WIFEXITED(jobs_id.status))
			{
				pj(jobs[index], index, "EXITED");
				var_return(WEXITSTATUS(jobs_id.status));
				jobs[index] = (t_jobs){0, 0, 0, 0, 0, 0};
			}
			else if (WIFSIGNALED(jobs_id.status))
			{
				pj(jobs[index], index, "SIGNALED");
				jobs[index] = (t_jobs){0, 0, 0, 0, 0, 0};
				var_return(WTERMSIG(jobs_id.status) + 128);
			}
			else if (WIFCONTINUED(jobs_id.status))
			{
				log_info("Continued [%d]", jobs[index].pid);
				jobs[index] = jobs_id;
				jobs[index].running = true;
			}
			else if (WIFSTOPPED(jobs_id.status))
			{
				log_info("Stopped [%d]", jobs[index].pid);
				jobs[index] = jobs_id;
				jobs[index].foreground = false;
				jobs[index].running = false;
				var_return(WTERMSIG(jobs_id.status) + 128);
			}
			else
			{
				log_fatal("There is probleme");
				jobs[index] = (t_jobs){0,0,0,0,0,0};
			}
			pj(jobs[index], index, "UPDATE STATUS");

			break ;
		}
		index--;
	}
}

static void		send_signal(t_jobs *jobs, t_jobs jobs_id, int sig)
{
	int index;
static int i;

	i++;
	if (i == 10)
		exit(45);
	index = MAX_CHILD;
	(void) jobs_id;
	log_error("SIGNAL_RECEPTION [%d] [%d]", sig, jobs_id.pid);
	if (jobs_id.pid != -1)
		index = jobs_id.pid;
	else
	{
		while (index >= 0)
			if (jobs[index].pid && jobs[index].foreground)
				break;
			else
				index--;
	}
		log_trace("%d", index);
		if (index != -1)
		{
			pj(jobs[index], index, "KILL SEND");
			kill(-jobs[index].pgid, sig);
		}
		else if (sig == SIGINT)
		{
			log_info("Send KEY_INTERRUPT to shell");
			ioctl(0, TIOCSTI, "\2\0");
		}
		else
		{
			log_warn("Signal nothing done ! ");
			bip();
		}
//	}

}

static void		put_in_foreground(t_jobs *jobs, t_jobs jobs_id)
{
	//check if status is WIFSTOPPED(status)
	int index;

	log_error("In Foreground [%d]",jobs_id.pid);
	index = MAX_CHILD;
	(void)jobs_id;
	if (jobs_id.pid != -1)
		index = jobs_id.pid;
	else
		while (index >= 0)
			if (jobs[index].pid && !jobs[index].foreground)
				break ;
			else
			index--;
	log_info("INdex in fg %d", index);
	if (index != -1)
	{
		jobs[index].foreground = true;
		pj(jobs[index], index, "FOREGROUND");
		if (jobs[index].running == false)
			kill(-jobs[index].pgid, SIGCONT);
		jobs[index].running = true;
		waitpid(jobs[index].pgid, &(jobs[index].status), WUNTRACED);
		jobs_control(UPDATE_CHILD, jobs[index], 0);
	}
	else if (var_return(1))
		STR_FD("Job's control : no current job\n", STDERR_FILENO);
}

static void		put_in_background(t_jobs *jobs, t_jobs jobs_id)
{
	int index;

	log_error("In background");
	index = MAX_CHILD;
	(void)jobs_id;
	if (jobs_id.pid != -1)
		index = jobs_id.pid;
	else
		while (index >= 0)
			if (jobs[index].pid && !jobs[index].running && !jobs[index].foreground)
				break;
			else
				index--;
	log_info("INdex in bg %d", index);
	if (index != -1)
	{
		jobs[index].foreground = false;
		pj(jobs[index], index, "BACKGROUND");
		if (jobs[index].running == false)
			kill(-jobs[index].pgid, SIGCONT);
		jobs[index].running = true;
		kill(-jobs[index].pgid, SIGCONT);
		waitpid(jobs[index].pgid, &(jobs[index].status), WUNTRACED | WCONTINUED | WNOHANG);
		jobs_control(UPDATE_CHILD, jobs[index], 0);
		log_info("BG END Find a background PPID [%d]", jobs[index].pid);
	}
	else if (var_return(1))
		STR_FD("Job's control : no current job\n", STDERR_FILENO);
}
void		full_update(t_jobs *jobs)
{
	int			index;

	log_error("[SIGCHLD] Update..");
	index = MAX_CHILD;
	while (index >= 0)
	{
		if (jobs[index].pid && !jobs[index].running)
		{
			pj(jobs[index],index, "FULL UPDATE");
			if ((waitpid(jobs[index].pid, &(jobs[index].status),
						 WUNTRACED | WNOHANG | WCONTINUED)) != -1)
			{
				log_info("Updating [%d]",jobs[index].pid);
				update_status(jobs, jobs[index]);
			}
		}
		index--;
	}
}

void		jobs_control(unsigned int flags, t_jobs jobs_id, int sig)
{
	static t_jobs			jobs[MAX_CHILD + 1];

	(void)sig;
	(void)jobs_id;
	if ((flags & INITIALIZE_TO_ZERO))
		ft_memset(&jobs, 0, sizeof(t_jobs) * (MAX_CHILD + 1));
	else if ((flags & NEW_CHILD))
		add_new_child(jobs, jobs_id);
	else if ((flags & SIGNAL_RECEPTION))
		send_signal(jobs, jobs_id, sig);
	else if ((flags & SIGNAL_SIGCHLD))
		full_update(jobs);
	else if ((flags & UPDATE_CHILD))
		update_status(jobs, jobs_id);
	else if ((flags & FOREGROUND))
		put_in_foreground(jobs, jobs_id);
	else if ((flags & BACKGROUND))
		put_in_background(jobs, jobs_id);
}
