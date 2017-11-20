//
// Created by Alexandre ROULIN on 11/20/17.
//

#include <sh.h>

t_jobs		*get_real_jobs(void)
{
	t_jobs		*jobs;
	int			index;

	index = 0;
	jobs = jobs_table();
	while (CHILD(index))
	{
		if (jobs[index].process)
			return (jobs + index);
		index++;
	}
	return (NULL);
}