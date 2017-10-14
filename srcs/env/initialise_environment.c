//
// Created by Alexandre ROULIN on 10/14/17.
//

#include <sh.h>

int					check_from_local_env(char **env, char *var)
{
	int		index;
	int		c;

	index = -1;
	if (env)
		while (env[++index])
		{
			c = 0;
			while (env[index][c] == var[c])
			{
				if (var[c] == '=')
					return (1);
				c++;
			}
		}
	return (0);
}
char					**start_from_full(char **command)
{
	char		**env;
	char		**cpy;
	int			index_env;
	int			index;
//	int			ret;

	index = -1;
	while (command[++index] && ft_chrchar(command[index], '='))
		if (ft_strlen(command[index]) == 1)
			return (error_env());
	env = env_table(NULL, ENV_REC);
	cpy = (char **)ft_memalloc(sizeof(char *) * (ft_tablen(env) + index + 1));
	index = -1;
	index_env = -1;
	while (command[++index] && ft_chrchar(command[index], '='))
		if (!check_from_local_env(cpy, command[index]))
			cpy[++index_env] = ft_strdup(command[index]);
	index = -1;
	if (env)
		while (env[++index])
			if (!check_from_local_env(cpy, env[index]))
				cpy[++index_env] = ft_strdup(env[index]);
	return (cpy);
}

char					**start_from_null(char **command)
{
	char		**cpy;
	int			index;
	int			index_env;

	index = -1;
	index_env = -1;
	while (command[++index] && ft_chrchar(command[index], '='))
		if (ft_strlen(command[index]) == 1)
			return (error_env());
	cpy = (char **)ft_memalloc(sizeof(char *) * (index + 1));
	index = -1;
	while (command[++index] && ft_chrchar(command[index], '='))
		if (!check_from_local_env(cpy, command[index]))
			cpy[++index_env] = ft_strdup(command[index]);
	return (cpy);
}

char					**start_from_less(char **command)
{
	char		**env;
	char		**cpy;
	int			t;
	int			c;

	if (!*command)
		return (env_table(NULL, ENV_CPY));
	if (ft_chrchar(command[0], '=') && ft_strlen(command[0]) == 1)
		return (error_env());
	else if (check_from_local_env((env = env_table(NULL, ENV_REC)), command[0]))
	{
		cpy = (char **)ft_memalloc(sizeof(char *) * (ft_tablen(env)));
		t = -1;
		c = -1;
		while (env[++t])
			if (!compare_environment(command[0], env[t]))
				cpy[++c] = ft_strdup(env[t]);
		cpy[++c] = NULL;
		return (cpy);
	}
	else
		return (env_table(NULL, ENV_CPY));
}