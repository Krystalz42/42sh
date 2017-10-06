

#include <sh.h>

static void print(t_jobs *jobs)
{
	int 		index;

	index = 0;
	log_trace("Print Beg : Struct Job's");
	while (index < MAX_CHILD && jobs[index].ppid)
	{
		log_info("PPID [%d] FG [%d] IND [%d] in %d", jobs[index].ppid,jobs[index].foreground,jobs[index].index, index);
		index++;
	}
	log_trace("Print End : Struct Job's");
}

static void reorganized_jobs(t_jobs *jobs, int index)
{
	if (index > 1)
		while (index < MAX_CHILD)
			if (jobs[index + 1].ppid)
			{
				jobs[index].ppid = jobs[index + 1].ppid;
				jobs[index].status = jobs[index + 1].status;
				jobs[index].foreground = jobs[index + 1].foreground;
				index++;
			}
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

	index = 0;
	while (index < MAX_CHILD && jobs[index].ppid)
		index++;
	if (jobs[index].ppid == 0)
	{
		log_info("New child has been added in index [%d]", index);
		jobs[index] = new_child(child, status, fg);
	}
}

static void		update_status(t_jobs *jobs, pid_t child, int status)
{
	int		index;

	index = 0;
	while (index < MAX_CHILD && jobs[index].ppid && jobs[index].ppid != child)
		index++;
	if (jobs[index].ppid == child)
	{
		if (WIFSIGNALED(status))
		{
			log_info("SIGN Pid [%d] has been killed by [%d]", child, WTERMSIG(status) + 128);
			if (WTERMSIG(status) == SIGTSTP)
			{
				log_trace("Job's suspend");
				jobs[index] = new_child(jobs[index].ppid, status, false);
			}
			else
			{
				jobs[index] = new_child(0, 0, false);
				reorganized_jobs(jobs, index);
			}
			var_return(WTERMSIG(status));
		}
		else if (WIFEXITED(status))
		{
			log_info("EXIT Pid [%d] has been exited by [%d]", child, WEXITSTATUS(status));
			var_return(WEXITSTATUS(status));
			jobs[index] = new_child(0, 0, false);
			reorganized_jobs(jobs, index);
			log_info("jobs[%d].%d RESETED", index, child);
		}
	}
	print(jobs);
}

static void		send_signal(t_jobs *jobs, int sig)
{
	int			index;
	int			status;

	index = 0;
	while (index < MAX_CHILD)
		if (jobs[index].ppid && jobs[index].foreground)
			break ;
		else
			index++;
	if (jobs[index].ppid)
	{
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
		log_info("Send 2 to shell");
		ioctl(0, TIOCSTI, "\x2\x0");
	}
	else
		bip();
}

static void		put_in_foreground(t_jobs *jobs, int jobs_spec)
{
	int			index;

	index = 0;
	(void)jobs_spec;
	while (index < MAX_CHILD && jobs[index].ppid)
		if (!jobs[index].foreground)
			break ;
		else
			index++;
	if (!jobs[index].foreground)
	{
		log_info("Find a background PPID [%d]", jobs[index].ppid);
		jobs[index].foreground = true;
		kill(-jobs[index].ppid, SIGCONT);
		my_wait(jobs[index].ppid, jobs[index].foreground);
	}
}

void		jobs_control(unsigned int flags, pid_t child, int status, int sig)
{
	static t_jobs			jobs[MAX_CHILD + 1];

	if ((flags & INITIALIZE_TO_ZERO))
	{
		log_success("On va retry allez STP !!!");
		ft_memset(&jobs, 0, sizeof(t_jobs) * MAX_CHILD + 1);
	}
	else if ((flags & NEW_CHILD_FG))
		add_new_child(jobs, child, status, true);
	else if ((flags & NEW_CHILD_BG))
		add_new_child(jobs, child, status, false);
	else if ((flags & UPDATE_CHILD))
		update_status(jobs, child, status);
	else if ((flags & SIGNAL_RECEPTION))
		send_signal(jobs, sig);
	else if ((flags & FOREGROUND))
		put_in_foreground(jobs, child);
}