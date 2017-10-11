//
// Created by Alexandre ROULIN on 10/11/17.
//

#include <sh.h>

void pj(t_process identify, int index, char *inc)
{
	log_trace("%s PID [%d] PGID [%d] RUNING [%d] FG [%d] INDEX [%d]"
	,inc, identify.pid,identify.pgid, identify.running, identify.foreground, index);

}

void pjt(t_jobs jobs, int index)
{
	int 	i;

	i = 0;
	log_info("Print Job's");
	pj(jobs.father,index, "Parent ... ");
	while (jobs.child[i].pid)
	{
		pj(jobs.child[i], i, "Child ...");
		i++;
	}
}