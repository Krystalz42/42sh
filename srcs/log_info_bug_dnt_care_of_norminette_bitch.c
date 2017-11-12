//
// Created by Alexandre ROULIN on 10/11/17.
//

#include <sh.h>

void pjt(t_jobs *jobs)
{
	t_process		*temp;

	temp = jobs->process;
	if (temp)
	{
		while (temp)
		{
			log_trace("PID [%d] PGID [%d] RUNING [%d] FOREGROUND [%d]",
					  jobs->process->pid,jobs->process->pgid,jobs->process->running,jobs->process->foreground);
			temp = temp->next;
		}
	}
	else
		log_trace("PROCESS NULLIFIER");
}