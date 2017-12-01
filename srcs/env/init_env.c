/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <aroulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 23:16:36 by aroulin           #+#    #+#             */
/*   Updated: 2017/11/17 15:06:54 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

static char		**cpy_table(char **env)
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

char			**env_table(char **env, int flags)
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



void			init_env(void)
{
	extern char		**environ;
	int				i;
	char			**env;

	env = (char **)ft_memalloc(sizeof(char *) * (ft_tablen(environ) + 1));
	i = 0;
	while (environ[i])
	{
		env[i] = ft_strdup(environ[i]);
		i++;
	}
	env[i] = NULL;
	env_table(env, ENV_INIT);
	add_environment("LSCOLORS=Cxfxgxdxbxegedabagacad");
}
