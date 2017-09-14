/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_list_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 23:22:31 by aroulin           #+#    #+#             */
/*   Updated: 2017/08/31 21:36:24 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

static inline	t_env		*init_list_env(char *name, char *value)
{
	t_env		*element;

	if (!(element = (t_env *)ft_memalloc(sizeof(t_env))))
		return (NULL);
	element->name = name;
	element->value = value;
	element->next = NULL;
	return (element);
}

void			add_list_env(char *name, char *value)
{
	t_env		*env;

	if (!(env = gbl_save_env(ENV_REC, NULL)))
		gbl_save_env(ENV_INIT, init_list_env(name, value));
	else
	{
		while (env->next)
			env = env->next;
		env->next = init_list_env(name, value);
	}
}
