//
// Created by Alexandre ROULIN on 10/6/17.
//

#include <sh.h>

void						my_wait(t_jobs jobs_id)
{
	if (jobs_id.foreground)
	{
		if ((waitpid(jobs_id.pid, &jobs_id.status, WUNTRACED)) != -1)
		{
			log_trace("End wait");
			jobs_control(UPDATE_CHILD, jobs_id, 0);
		}
	}
	else
		if ((waitpid(jobs_id.pid, &jobs_id.status, WUNTRACED | WNOHANG)) != -1)
			jobs_control(UPDATE_CHILD, jobs_id, 0);
}