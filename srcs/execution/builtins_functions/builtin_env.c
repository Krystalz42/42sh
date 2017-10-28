//
// Created by Alexandre ROULIN on 10/27/17.
//

#include <sh.h>

uint8_t			fct(char **command, char **env)
{
	log_trace("%s", *command);
	if (*command)
		check_if_builtin(command, env);
	else
		ft_putstrtab(env, 10);
	return (1);
}

uint8_t			builtin_env(char **command, char **env)
{
	int				index;
	int				opt;
	int				table;
	int				ret;

	table = 0;
	opt = 0;
	if (ft_strcmp(command[1], HELP) == 0)
		return (var_return(usage_env()));
	while (command[++table] && command[table][0] == '-')
	{
		index = -1;
		while (command[table][++index])
			if (command[table][index] == 'u' || command[table][index] == 'i')
				opt = command[table][index];
	}
	if (opt == 'i' && (ret = start_from_null(command + table, &env)) != -1)
		fct(command + table + ret, env);
	if (opt == 'u' && (ret = start_from_less(command + table, &env)) != -1)
		fct(command + table + ret, env);
	if ((opt == 0 && (ret = start_from_full(command + table, &env)) != -1))
		fct(command + table + ret, env);
	if (ret != -1)
		ft_memdel_tab(&env);
	return (0);
}