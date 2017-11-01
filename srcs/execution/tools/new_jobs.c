//
// Created by Alexandre ROULIN on 11/1/17.
//

#include <sh.h>

t_jobs				*new_jobs()
{
	t_jobs		*jobs;
	int			index;

	index = MAX_CHILD - 1;
	jobs = jobs_table();
	while (index >= 0 && jobs[index].process == NULL)
		index--;
	if (index == MAX_CHILD - 1)
	{
		error_builtin("jobs: ", "too much process: ", NULL);
		return (NULL);
	}
	else
	{
		jobs += index;
		jobs->index = index + 1;
		log_trace("jobs [%d] created", index);
		return (jobs);
	}
}