//
// Created by Alexandre ROULIN on 10/12/17.
//

#include <sh.h>

uint8_t			builtin_jobs(char **command, char **env)
{
	int			table;
	int			option;
	int			index;

	option = 0;
	table = 1;
	index = 0;
	(void)env;
	log_debug("Jobs'control builtins");
	while (command[table] && command[table][index] == '-')
		while (command[table][index])
		{
			option += (command[table][index] == 'p') ? 1 : 0;
			option += (command[table][index] == 'r') ? 2 : 0;
			option += (command[table][index] == 's') ? 4 : 0;
		}
	return (var_return(jobs_control(PRINT_JOBS, new_jobs(0), option)));
}
