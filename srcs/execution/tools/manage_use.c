//
// Created by Alexandre ROULIN on 11/20/17.
//

#include <sh.h>

t_jobs			*add_next_use(t_jobs *new)
{
	t_jobs		*jobs;

	jobs = jobs_table(REC_STRUCT);
	while (jobs && jobs->next_use)
		jobs = jobs->next_use;
	if (jobs && jobs != new)
	{
		new->prev_use = jobs;
		jobs->next_use = new;
	}
	return (new);
}