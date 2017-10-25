//
// Created by Alexandre ROULIN on 10/12/17.
//

#include <sh.h>

/*

-l 8

		List process IDs in addition to the normal information.
-p 1

		List only the process ID of the job’s process group leader.
-r 2

		Display only running jobs.
-s 4

		Display only stopped jobs.
*/

int			print_process(t_process process, int info, int parent, int index)
{
	if (process.pid == process.pgid)
		ft_printf("[%d]\t", index + 1);
	else if (parent && process.pid != process.pgid)
		return (1);
	else
		ft_putchar('\t');
	if (info)
		ft_printf("\t%d %s %s\n", process.pid, process.running ? "Runing" : "Stopped", process.command);
	else
		ft_printf("\t%s %s\n", process.running ? "Runing" : "Stopped", process.command);
	return (1);
}

uint8_t			print_jobs(t_jobs *jobs, int opt)
{
	int			i;
	int			ind_c;

	i = 0;
	while (i < MAX_CHILD)
	{
		ind_c = 0;
		while (jobs[i].process[ind_c].pid)
		{
			if ((opt & 2) && jobs[i].process[ind_c].running)
				print_process(jobs[i].process[ind_c], (opt & 8), (opt & 1), i);
			else if ((opt & 4) && jobs[i].process[ind_c].running == false)
				print_process(jobs[i].process[ind_c], (opt & 8), (opt & 1), i);
			else if (!(opt & 2) && !(opt & 4))
				print_process(jobs[i].process[ind_c], (opt & 8), (opt & 1), i);
			ind_c++;
		}
		i++;
	}
	return (0);
}

uint8_t			builtin_jobs(char **command, char **env)
{
	int					table;
	int					opt;
	int					index;

	opt = 0;
	table = 1;
	(void)env;
	while (command[table] && command[table][0] == '-')
	{
		index = 0;
		while (command[table][index])
		{
			opt += (command[table][index] == 'p' && !(opt & 1)) ? 1 : 0;
			opt += (command[table][index] == 'r' && !(opt & 2)) ? 2 : 0;
			opt += (command[table][index] == 's' && !(opt & 4)) ? 4 : 0;
			opt += (command[table][index] == 'l' && !(opt & 8)) ? 8 : 0;
			index++;
		}
		table++;
	}
	return (var_return(print_jobs(jobs_table(), opt)));
}
