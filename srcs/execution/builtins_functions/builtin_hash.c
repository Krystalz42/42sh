//
// Created by Alexandre ROULIN on 10/13/17.
//

#include <sh.h>

/*
**			default print hash table
**	-r	:	reset hash table
*/

uint8_t			builtin_hash(char **command, char **env)
{
	int		index;
	int		option;
	int		c;

	(void)env;
	option = 0;
	index = 0;
	while (command[++index] && (command[index][0]) == '-' && (c = -1))
		while (command[index][++c])
			if (command[index][c] == 'r')
				option = 1;
	return (option ? hash_reset() : hash_print(STDOUT_FILENO));
}