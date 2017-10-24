//
// Created by Alexandre ROULIN on 10/12/17.
//

#include <sh.h>

uint8_t			print_jobs(t_jobs *jobs, int opt)
{
	int			index;

	index = 0;
	opt++;
	while (index < MAX_CHILD)
	{
		if (jobs[index].process->pid)
		{

		}
		index++;
	}
	return (0);
}

uint8_t			builtin_jobs(char **command, char **env)
{
	int			table;
	int			opt;
	int			index;

	opt = 0;
	table = 1;
	(void)env;
	while (command[table] && command[table][0] == '-')
	{
		index = 0;
		while (command[table][index])
		{
			opt += (command[table][index] == 'p' && !(opt % 2)) ? 1 : 0;
			opt += (command[table][index] == 'r' && (opt % 4 < 2)) ? 2 : 0;
			opt += (command[table][index] == 's' && (opt < 4)) ? 4 : 0;
			index++;
		}
		table++;
	}
	return (var_return(print_jobs(jobs_table(), opt)));
}
