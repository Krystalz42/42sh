/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 04:25:19 by aroulin           #+#    #+#             */
/*   Updated: 2017/10/04 21:01:52 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

uint8_t					test(char **command, char **env)
{
	END("LES COMMAND !!");
	ft_putstrtab(command, '\n');
	END("LENVIRONEMENT !!");
	ft_putstrtab(env, '\n');
	return (0);
}

static u_int8_t			start_from_full(char **command)
{
	char		**env;
	char		**cpy;
	int			t;
	int			c;

	t = -1;
	while (command[++t] && ft_chrchar(command[t], '='))
		;
	env = env_table(NULL, ENV_REC);
	cpy = (char **)ft_memalloc(sizeof(char *) * (ft_tablen(env) + t + 1));
	t = -1;
	while (env[++t])
		cpy[t] = ft_strdup(env[t]);
	c = -1;
	while (command[++c] && ft_chrchar(command[c], '='))
		cpy[t++] = ft_strdup(command[c]);
	return (test(command + c, cpy));
}

static uint8_t			start_from_null(char **command)
{
	char		**env;
	int			t;

	t = -1;
	while (command[++t] && ft_chrchar(command[t], '='))
		;
	env = (char **)ft_memalloc(sizeof(char *) * (t + 1));
	t = -1;
	while (command[++t] && ft_chrchar(command[t], '='))
		env[t] = ft_strdup(command[t]);
	return (test(command + t, env));
}

static uint8_t			start_from_less(char **command)
{
	char		**env;
	char		**cpy;
	int			t;
	int			c;

	env = env_table(NULL, ENV_REC);
	if (my_getenv(command[0]))
	{
		cpy = (char **)ft_memalloc(sizeof(char *) * (ft_tablen(env)));
		t = -1;
		c = -1;
		while (env[++t])
			if (!compare_environment(command[0], env[t]))
				cpy[++c] = ft_strdup(env[t]);
		cpy[++c] = NULL;
		return (test(command + 1, cpy));
	}
	else
		return (test(command + 1, env_table(NULL, ENV_REC)));
}

uint8_t					builtin_env(char **command)
{
	int				index;
	int				option;
	int				t;

	t = 0;
	option = 0;
	while (command[++t] && command[t][0] == '-')
	{
		index = -1;
		while (command[t][++index])
			if (command[t][index] == 'u' || command[t][index] == 'i')
				option = command[t][index];

	}
	if (option == 'i')
		return (start_from_null(command + t));
	else if (option == 'u')
		return (start_from_less(command + t));
	else
		return (start_from_full(command + t));
}