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
	int 		i;

	i = 0;
	while (jobs.process[i].pid)
	{
		log_trace("PID [%d] PGID [%d] RUNING [%d] FOREGROUND [%d] INDEX [%d] INDEX_CHILD [%d]", jobs.process[i].pid,jobs.process[i].pgid,jobs.process[i].running,jobs.process[i].foreground, index, i);
		i++;
	}
	if (i == 0)
		log_trace("PID [%d] PGID [%d] RUNING [%d] FOREGROUND [%d] i [%d] INDEX_CHILD [%d]", jobs.process[i].pid,jobs.process[i].pgid,jobs.process[i].running,jobs.process[i].foreground, index, i);
}