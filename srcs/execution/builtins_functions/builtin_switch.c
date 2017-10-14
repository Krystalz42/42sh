//
// Created by Alexandre ROULIN on 10/14/17.
//

#include <sh.h>

uint8_t		builtin_foreground(char **command, char **env)
{
	int			id;

	(void)env;
	id = -1;
	if (command[1] && command[1][0] == '%')
		id = ft_atoi(command[1] + 1);
	jobs_control(FOREGROUND, new_jobs(id), 0);
	return (var_return(-1));
}

uint8_t		builtin_background(char **command, char **env)
{
	int			id;

	(void)env;
	id = -1;
	if (command[1] && command[1][0] == '%')
		id = ft_atoi(command[1] + 1);
	jobs_control(BACKGROUND, new_jobs(id), 0);
	return (var_return(-1));
}