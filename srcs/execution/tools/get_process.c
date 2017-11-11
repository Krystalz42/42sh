//
// Created by Alexandre ROULIN on 11/10/17.
//

#include <sh.h>

t_process			*get_process(t_jobs *jobs, pid_t pid)
{
	if (jobs)
	{
		if (jobs->process)
		{
			while (jobs->process->prev)
				jobs->process = jobs->process->prev;
			while (jobs->process)
			{
				if (jobs->process->pid == pid)
					return (jobs->process);
				jobs->process = jobs->process->next;
				if ()
			}
		}
	}
	return (NULL);
}