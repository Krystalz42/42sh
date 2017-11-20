//
// Created by Alexandre ROULIN on 11/20/17.
//

#include <sh.h>

int						check_jobs_spec(char **command, char *from)
{
	int			table;
	int			jobs_spec;

	table = 1;
	if (command[table] && command[table][0] == '%')
	{
		if ((jobs_spec = ft_atoi(command[table] + 1)) < 1)
			return (error_msg(from, NO_CUR_JOB, command[table]) - 2);
	}
	else if (command[table])
		return (error_msg(from, NO_CUR_JOB, command[table]) - 2);
	else
		jobs_spec = 0;
	return (jobs_spec);
}


static t_jobs			*get_last_jobs(t_jobs *jobs, const char *from)
{
	if (from == BG)
	{
		while (jobs)
		{
			if (jobs->process->running == false)
				return (jobs);
			jobs = jobs->prev_use;
		}
	}
	else if (from == FG)
	{
		while (jobs)
		{
			if (jobs->process->foreground == false)
				return (jobs);
			jobs = jobs->prev_use;
		}
	}
	(from == BG) ? error_msg(BG, JOBS_IN_BG, NULL) : 0;
	return (NULL);
}

t_jobs					*get_jobs_by_setting(int index, char *from)
{
	t_jobs		*jobs;

	if ((jobs = *jobs_table()) == NULL)
	{
		error_msg(from, NO_CUR_JOB, NULL);
		return (NULL);
	}
	if (index)
	{
		while (jobs && jobs->index != index)
			jobs = jobs->next;
		if (jobs && jobs->index == index)
			return (jobs);
	}
	else
	{
		while (jobs->next_use)
			jobs = jobs->next_use;
		return (get_last_jobs(jobs, from));
	}
	return (NULL);
}