//
// Created by Alexandre ROULIN on 10/6/17.
//

#include <sh.h>

void						my_wait(t_jobs jobs_id)
{
	int			jobs_spec;
	int			index;

	index = -1;
	jobs_spec = jobs_control(NEW_CHILD, jobs_id, 0);
	if (jobs_id.father.foreground)
	{
		if ((waitpid(jobs_id.father.pid, &jobs_id.father.status, WUNTRACED)) != -1)
		{
			jobs_control(UPDATE_CHILD, jobs_id, 0);
		}
	}
	else
	{
		if ((waitpid(jobs_id.father.pid, &jobs_id.father.status, WUNTRACED | WNOHANG)) != -1)
			jobs_control(UPDATE_CHILD, jobs_id, 0);
	}
}