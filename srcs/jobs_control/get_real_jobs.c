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
		dprintf(fd_log, "sdYo2\n");
		if (jobs[index].process)
		{
			dprintf(fd_log, "sdsYo2\n");
			jobs += index;
			while (jobs->next_use)
			{
				dprintf(fd_log, "adYo2\n");
				jobs = jobs->next_use;

			}
			return (jobs);
		}
		index++;
	}
	return (NULL);
}