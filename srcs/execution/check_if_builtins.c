//
// Created by Alexandre ROULIN on 10/14/17.
//

#include <sh.h>

static const t_builtin	builtin[] = {
	(t_builtin){"env", NULL},
	(t_builtin){"setenv", NULL},
	(t_builtin){"unsetenv", NULL},
	(t_builtin){"cd", NULL},
	(t_builtin){"echo", NULL},
	(t_builtin){"jobs", builtin_jobs},
	(t_builtin){"history", builtin_history},
	(t_builtin){"hash", builtin_hash},
	(t_builtin){"exit", NULL},
	(t_builtin){NULL, NULL}
};

int				check_if_builtin(char **command, char **env)
{
	int		index;

	index = 0;
	while (builtin[index].str)
	{
		if (!ft_strcmp(builtin[index].str, command[0]))
			return (var_return(builtin[index].function(command, env)));
		index++;
	}
	return (-1);
}