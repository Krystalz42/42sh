/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_table.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 18:20:23 by aroulin           #+#    #+#             */
/*   Updated: 2017/09/23 19:45:50 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

char				**gbl_save_table(char **env)
{
	static char **save;

	if (env)
		save = env;
	return (save);
}

static char			*envjoin(t_env *env)
{
	char	*tmp;

	tmp = (char *)ft_memalloc(ft_strlen(env->name) + ft_strlen(env->value) + 2);
	ft_strcpy(tmp, env->name);
	ft_strcpy(tmp + ft_strlen(tmp), "=");
	ft_strcpy(tmp + ft_strlen(tmp), env->value);
	return (tmp);
}

void				create_table_env(void)
{
	t_env		*env;
	char		**table;
	int			i;
	int			c;

	i = 0;
	c = -1;
	if ((env = gbl_save_env(ENV_REC, NULL)))
	{
		while (env && ++i)
			env = env->next;
		table = (char **)ft_memalloc(sizeof(char *) * (i + 1));
		table[i] = NULL;
		env = gbl_save_env(ENV_REC, NULL);
		i = -1;
		while (env)
		{
			table[++i] = envjoin(env);
			env = env->next;
		}
		gbl_save_table(table);
	}
}
