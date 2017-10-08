//
// Created by Alexandre ROULIN on 10/6/17.
//

#include <sh.h>

void		my_wait(pid_t child, bool foreground, bool parent)
{
	t_jobs		jobs_id;

	setpgid(child, child);
	jobs_id = (t_jobs){child, getpgid(child), 0, foreground, parent, true};
	jobs_control(NEW_CHILD, jobs_id, 0);
	if (foreground)
	{
		if ((waitpid(jobs_id.pid, &(jobs_id.status), WUNTRACED | WCONTINUED)) != -1)
		{
			jobs_control(UPDATE_CHILD, jobs_id, 0);
		}
		else
		{
			log_error("Waitpid return -1 nothing to do");
		}
	}
	else
	{
		if ((waitpid(jobs_id.pid, &(jobs_id.status), WUNTRACED | WNOHANG)) != -1)
			jobs_control(UPDATE_CHILD, jobs_id, 0);

	}
}