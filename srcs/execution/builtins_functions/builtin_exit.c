//
// Created by Alexandre ROULIN on 10/27/17.
//

#include <sh.h>

uint8_t				builtin_exit(char **command, char **env)
{
	int var;

	(void)env;
	if (command[1] && command[2] == NULL)
	{
		if (ft_strisdigit(command[1]))
			var = ft_atoi(command[1]);
		else
		{
			error_builtin(EXIT, NUM_REQUIRED, command[1]);
			var = 255;
		}
		b_write_history_in_file(get_str_from_history());
		ft_putendl("exit");
		exit(var);
	}
	else if (command[2])
		return (error_builtin(EXIT, TOO_MANY_ARGS, NULL));
	else
		exit_();
	return (0);
}