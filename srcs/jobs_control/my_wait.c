//
// Created by Alexandre ROULIN on 10/6/17.
//

#include <sh.h>

void		my_wait(pid_t child, bool foreground)
{
	t_jobs		jobs_id;

	setpgid(child, child);
	jobs_id = (t_jobs){child, getpgid(child), 0, foreground, false, true};
	jobs_control(NEW_CHILD, jobs_id, 0);
	log_trace("setpgid(%d, %d)", child, child);
	if (foreground)
	{
		log_info("Waiting [%d] in [%d]", child, jobs_id.foreground);
		if ((waitpid(jobs_id.pid, &(jobs_id.status), WUNTRACED | WCONTINUED)) != -1)
		{
			log_info("Child [%d] will be update", child);
			jobs_control(UPDATE_CHILD, jobs_id, 0);
		}
		else
		{
			log_error("Waitpid return -1 nothing to do");
		}
	}
	else
	{
		log_info("Waiting [%d] in [%d]", child, jobs_id.foreground);
		if ((waitpid(jobs_id.pid, &(jobs_id.status), WUNTRACED | WNOHANG)) != -1)
			jobs_control(UPDATE_CHILD, jobs_id, 0);

	}
}