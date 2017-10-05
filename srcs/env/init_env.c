/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 23:16:36 by aroulin           #+#    #+#             */
/*   Updated: 2017/08/10 00:05:00 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

char		**cpy_table(char **env)
{
	char	**cpy;
	int		i;

	i = -1;
	if (env)
	{
		cpy = (char **)ft_memalloc(sizeof(char *) * (ft_tablen(env) + 1));
		while (env[++i])
			cpy[i] = ft_strdup(env[i]);
		return (cpy);
	}
	return (NULL);
}

char 		**env_table(char **env, int flags)
{
	static char		**save;

	if ((ENV_NULL & flags))
		save = NULL;
	if ((ENV_INIT & flags))
		save = env;
	if ((ENV_REC & flags))
		return (save);
	if ((ENV_CPY & flags))
		return (cpy_table(save));
	return (NULL);
}

void		init_env(void)
{
	extern char		**environ;
	int				i;
	char 			**env;

	i = -1;
	env = NULL;
	log_error("bonjour j'init l'env");
	if (environ)
	{
		while (environ[++i])
			;
		env = (char **)ft_memalloc(sizeof(char *) * (i  + 1));
		i = -1;
		while (environ[++i])
			env[i] = ft_strdup(environ[i]);
		env[i] = NULL;
	}
	env_table(env, ENV_INIT);
}
