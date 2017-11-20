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
		{
			jobs += index;
			while (jobs->next_use)
				jobs = jobs->next_use;
			return (jobs);
		}
		index++;
	}
	return (NULL);
}