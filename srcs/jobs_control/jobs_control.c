

#include <sh.h>

void print(t_jobs *jobs)
{
	int 		index;

	index = 0;
	log_trace("Print Beg : Struct Job's");
	while (index < MAX_CHILD && jobs[index].ppid)
	{
		log_info("PPID [%d] FG [%d]  in %d", jobs[index].ppid,jobs[index].foreground, index);
		index++;
	}
	log_trace("Print End : Struct Job's");
}

static t_jobs new_child(pid_t child, int status, bool foreground)
{
	t_jobs			element;

	element.foreground = foreground;
	element.ppid = child;
	element.status = status;
	return (element);
}

static void		add_new_child(t_jobs *jobs, pid_t child, int status, bool fg)
{
	int			index;

	index = MAX_CHILD;
	while (index >= 0 && !jobs[index].ppid)
		index--;
	if (index != MAX_CHILD)
	{
		log_info("New child has been added in index [%d]", index + 1);
		jobs[index + 1] = new_child(child, status, fg);
	}
}

static void		update_status(t_jobs *jobs, pid_t child, int status)
{
	int		index;

	index = MAX_CHILD;
	while (index >= 0)
	{
		if (jobs[index].ppid == child)
		{
			if (WIFEXITED(status))
			{
				log_info("EXIT Pid [%d] has been exited by [%d]", child, WEXITSTATUS(status));
				var_return(WEXITSTATUS(status));
				jobs[index] = new_child(0, 0, false);
			}
			else if (WIFSIGNALED(status))
			{
				log_info("SIGN Pid [%d] has been killed by [%d]", child, WTERMSIG(status));
				if (WTERMSIG(status) == SIGTSTP)
				{
					log_trace("Job's suspend");
					jobs[index] = new_child(jobs[index].ppid, status, false);
				}
				else
					jobs[index] = new_child(0, 0, false);
				var_return(WTERMSIG(status) + 128);
			}
			else if (WIFCONTINUED(status))
			{
				log_info("Continued [%d]", jobs[index].ppid);
				jobs[index].status = status;
			}
			else if (WIFSTOPPED(status))
			{
				log_info("Stopped [%d]", jobs[index].ppid);
				jobs[index].foreground = false;
				jobs[index].status = status;
				var_return(WTERMSIG(status) + 128);
				print(jobs);
				log_trace("WIFSTOPPED(%d)", jobs[index].status);
			}
			break ;
		}
		index--;
	}
}

static void		send_signal(t_jobs *jobs, pid_t child, int sig)
{
	int			index;
	int			status;

	index = MAX_CHILD;
	log_success("SIGNAL RECIEVED [%d]", sig);
	if (child)
	{
		if (jobs[child].ppid)
			kill(jobs[index].ppid, sig);
	}
	else
	{
		while (index >= 0 && !(jobs[index].ppid && jobs[index].foreground))
			index--;
		if (index != -1)
		{
			log_info("PID FIND IN SIGNAL [%d] FG [%d]", jobs[index].ppid, jobs[index].foreground);
			if (sig == SIGCHLD && waitpid(jobs[index].ppid, &status, WUNTRACED | WCONTINUED))
				update_status(jobs, jobs[index].ppid, status);
			else
			{
				kill(-jobs[index].ppid, sig);
				log_info("Send signal [%d] to ppid [%d] index %d", sig, jobs[index].ppid, index);
			}
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

static void		put_in_foreground(t_jobs *jobs, int jobs_spec)
{
	//check if status is WIFSTOPPED(status)
	int index;
	int status;

	index = MAX_CHILD;
	if (jobs_spec != -1)
		index = jobs_spec;
	else
		while (index >= 0 && !jobs[index].ppid && !jobs[index].foreground)
			index--;
	if (index != -1)
	{
		log_info("FG Find a background PPID [%d]", jobs[index].ppid);
		jobs[index].foreground = true;
		kill(-jobs[index].ppid, SIGCONT);
		waitpid(jobs[index].ppid, &status, WUNTRACED);
		jobs_control(UPDATE_CHILD, jobs[index].ppid, status, 0);
		log_info("FG END Find a background PPID [%d]", jobs[index].ppid);
	}
	else if (var_return(1))
		STR_FD("Job's control : no current job\n", STDERR_FILENO);
	print(jobs);
}

void		full_update(t_jobs *jobs)
{
	int			index;
	pid_t  test;

	log_info("[SIGCHLD] Update..");
	index = MAX_CHILD;
	while (index >= 0)
	{
		if (jobs[index].ppid && !jobs[index].foreground)
			if ((test = waitpid(jobs[index].ppid, &(jobs[index].status), WUNTRACED | WNOHANG | WCONTINUED)))
			{
				log_error("Test = %d", test);
				log_info("Updating [%d]",jobs[index].ppid);
				update_status(jobs, jobs[index].ppid, jobs[index].status);
			}
		index--;
	}
}

static void		put_in_background(t_jobs *jobs, int jobs_spec)
{
	//check if status is WIFSTOPPED(status)
	int index;

	index = MAX_CHILD;
	if (jobs_spec != -1)
	{
		index = jobs_spec;
		log_trace("jobs_spec specified [%d]", jobs_spec);
	}
	else
	{
		log_trace("jobs_spec not specified [%d]", jobs_spec);
		while (index >= 0 && !jobs[index].ppid && !jobs[index].foreground && !WIFSTOPPED(jobs[index].status))
			index--;

	}
	if (index != -1)
	{
		log_info("BG PPID [%d] STATUS [%d] MAC [%d] in [%d]", jobs[index].ppid,jobs[index].foreground,WIFSTOPPED(jobs[index].status), index);
		jobs[index].foreground = false;
		kill(-jobs[index].ppid, SIGCONT);
		waitpid(jobs[index].ppid, &(jobs[index].status), WUNTRACED | WCONTINUED | WNOHANG);
		jobs_control(UPDATE_CHILD, jobs[index].ppid, jobs[index].status, 0);
		log_info("BG END Find a background PPID [%d]", jobs[index].ppid);
	}
	else if (var_return(1))
		STR_FD("Job's control : no current job\n", STDERR_FILENO);
	print(jobs);
}

void		jobs_control(unsigned int flags, pid_t child, int status, int sig)
{
	static t_jobs			jobs[MAX_CHILD + 1];

	if ((flags & INITIALIZE_TO_ZERO))
		ft_memset(&jobs, 0, sizeof(t_jobs) * (MAX_CHILD + 1));
	else if ((flags & NEW_CHILD_FG))
		add_new_child(jobs, child, status, true);
	else if ((flags & NEW_CHILD_BG))
		add_new_child(jobs, child, status, false);
	else if ((flags & UPDATE_CHILD))
		update_status(jobs, child, status);
	else if ((flags & SIGNAL_SIGCHLD))
		full_update(jobs);
	else if ((flags & SIGNAL_RECEPTION))
		send_signal(jobs, child, sig);
	else if ((flags & FOREGROUND))
		put_in_foreground(jobs, child);
	else if ((flags & BACKGROUND))
		put_in_background(jobs, child);
}
