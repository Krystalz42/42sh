//
// Created by Alexandre ROULIN on 10/6/17.
//

#include <sh.h>

void						my_wait(t_jobs jobs_id)
{
	int		index;
	int		index_child;

	index = jobs_control(NEW_CHILD, jobs_id, 0);
	if (jobs_id.father.foreground)
	{
		log_trace("Will wait in foreground");
		jobs_control(UPDATE_CHILD, jobs_id, WCONTINUED | WUNTRACED);
	}
	else
	{
		ft_printf("[%d] %8d %10s\n", index, jobs_id.father.pid, jobs_id.father.command);
		index_child = 0;
		while (jobs_id.child[index_child].pid)
		{
			ft_printf("    %8d %10s\n", jobs_id.child[index_child].pid, jobs_id.child[index_child].command);
			index_child++;
		}
		jobs_control(UPDATE_CHILD, jobs_id, WNOHANG | WUNTRACED | WCONTINUED);
	}

}