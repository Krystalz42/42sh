//
// Created by Alexandre ROULIN on 10/14/17.
//

#include <sh.h>

uint8_t env(char **c, char **e)
{
	(void)c;
	ft_putstrtab(e, 10);
	return (0);
}

static const t_builtin	builtin[] = {
	(t_builtin){"env", builtin_env},
	(t_builtin){"setenv", ft_setenv},
	(t_builtin){"unsetenv", ft_unsetenv},
	(t_builtin){"cd", ft_cd},
	(t_builtin){"echo", ft_echo},
	(t_builtin){"jobs", builtin_jobs},
	(t_builtin){"history", builtin_history},
	(t_builtin){"hash", builtin_hash},
	(t_builtin){"fg", builtin_foreground},
	(t_builtin){"bg", builtin_background},
	(t_builtin){"kill", builtin_kill},
	(t_builtin){"exit", builtin_exit},
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
