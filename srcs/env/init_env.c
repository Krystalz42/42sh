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

char 		**env_table(char **env, int flags)
{
	static char **save;

	if ((ENV_NULL & flags))
		save = NULL;
	if ((ENV_INIT & flags))
		save = env;
	if ((ENV_REC & flags))
		return (save);
	return (NULL);
}

void		init_env(void)
{
	extern char		**environ;
	int				i;
	char 			**env;

	i = -1;
	env = NULL;
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
