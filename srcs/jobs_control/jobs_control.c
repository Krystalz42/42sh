

#include <sh.h>

void pj(t_jobs jobs)
{
	log_info("PID [%d] PGID [%d] RUNING [%d] FG [%d] PIPE [%d] INDEX [%d]", jobs.pid,jobs.pgid, jobs.running, jobs.foreground, jobs.pipeline);

}

void print(t_jobs *jobs)
{
	int 		index;

	index = MAX_CHILD;
	log_trace("Print Beg : Struct Job's");
	while (index >= 0)
	{
		if (jobs[index].pid)
			pj(jobs[index]);
		index--;
	}
	log_trace("Print End : Struct Job's");
}

static void		add_new_child(t_jobs *jobs, t_jobs jobs_id)
{
	int			index;

	index = MAX_CHILD;
	while (index >= 0 && !jobs[index].pid)
		index--;
	if (index != MAX_CHILD)
	{
		log_info("NEW_CHILD : PID [%d] & PGID [%d] & FG [%d] INDEX [%d]", jobs_id.pid,jobs_id.pgid,jobs_id.foreground,index + 1);
		jobs[index + 1] = jobs_id;
	}
}

static void		update_status(t_jobs *jobs, t_jobs jobs_id)
{
	int		index;

	index = MAX_CHILD;
	while (index >= 0)
	{
		if (jobs[index].pid == jobs_id.pid)
		{
			if (WIFEXITED(jobs_id.status))
			{
				log_info("EXIT Pid [%d] has been exited by [%d]", jobs_id.pid, WEXITSTATUS(jobs_id.status));
				var_return(WEXITSTATUS(jobs_id.status));
				jobs[index] = (t_jobs){0, 0, 0, 0, 0, 0};
			}
			else if (WIFSIGNALED(jobs_id.status))
			{
				log_info("SIGN Pid [%d] has been killed by [%d]", jobs_id.pid, WTERMSIG(jobs_id.status));
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
				print(jobs);
			}
			break ;
		}
		index--;
	}
}

static void		send_signal(t_jobs *jobs, t_jobs jobs_id, int sig)
{
	int			index;

	index = MAX_CHILD;
	log_error("SIGNAL_RECEPTION [%d]", sig);
	sleep(1);
	if (jobs_id.pid)
	{
		kill(-jobs_id.pid, sig);
		perror("");
	}
	else
	{
		while (index >= 0 && !jobs[index].foreground)
			index--;
		if (index != -1)
		{
			log_info("SIGNAL_RECEPTION to PID [%d] PGID [%d]", jobs[index].pid,jobs[index].pgid);
			kill(-jobs[index].pid, sig);
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
	}

}

static void		put_in_foreground(t_jobs *jobs, t_jobs jobs_id)
{
	//check if status is WIFSTOPPED(status)
	int index;

	log_error("In Foreground");
	index = MAX_CHILD;
	(void)jobs_id;
	if (jobs_id.pid != -1)
		index = jobs_id.pid;
	else
		while (index >= 0 && !jobs[index].pid && jobs[index].foreground)
			index--;
	if (index != -1)
	{
		pj(jobs[index]);
		kill(-jobs[index].pgid, SIGCONT);
		waitpid(jobs[index].pgid, &(jobs[index].status), WUNTRACED);
		jobs_control(UPDATE_CHILD, jobs[index], 0);
		jobs[index].foreground = true;
	}
	else if (var_return(1))
		STR_FD("Job's control : no current job\n", STDERR_FILENO);
	print(jobs);
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
		while (index >= 0 && !jobs[index].pid && !jobs[index].foreground && !jobs[index].running)
			index--;
	if (index != -1)
	{
		pj(jobs[index]);
		kill(-jobs[index].pgid, SIGCONT);
		jobs[index].foreground = false;
		waitpid(jobs[index].pgid, &(jobs[index].status), WUNTRACED | WCONTINUED | WNOHANG);
		jobs_control(UPDATE_CHILD, jobs[index], 0);
		log_info("BG END Find a background PPID [%d]", jobs[index].pid);
		pj(jobs[index]);
	}
	else if (var_return(1))
		STR_FD("Job's control : no current job\n", STDERR_FILENO);
	print(jobs);
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
			log_trace("Update ... PID [%d] & PGID [%d] & RUNING [%d]",jobs[index].pid,jobs[index].pgid,jobs[index].running);
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
