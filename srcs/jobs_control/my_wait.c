//
// Created by Alexandre ROULIN on 10/6/17.
//

#include <sh.h>

void						my_wait(t_jobs jobs_id)
{
	pid_t test;
	if (jobs_id.foreground)
	{
		while ((test = waitpid(jobs_id.pid, &(jobs_id.status), WNOHANG)) != -1)
		{
			if (WIFSIGNALED(jobs_id.status) || WIFSTOPPED(jobs_id.status))
				break ;
		}
		jobs_control(UPDATE_CHILD, jobs_id, 0);
	}
	else
	{
		if ((waitpid(jobs_id.pid, &(jobs_id.status), WUNTRACED | WNOHANG)) != -1)
			jobs_control(UPDATE_CHILD, jobs_id, 0);

	}
}