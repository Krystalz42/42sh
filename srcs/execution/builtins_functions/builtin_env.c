//
// Created by Alexandre ROULIN on 10/27/17.
//

#include <sh.h>



uint8_t			builtin_env(char **command, char **env)
{
	int				index;
	int				option;
	int				table;

	table = 0;
	option = 0;
	while (command[++table] && command[table][0] == '-')
	{
		index = -1;
		while (command[table][++index])
			if (command[table][index] == 'u' || command[table][index] == 'i')
				option = command[table][index];

	}
	if (option == 'i')
		start_from_null(command + table);
	else if (option == 'u')
		start_from_less(command + table);
	else
		start_from_full(command + table);
}