/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 05:07:35 by aroulin           #+#    #+#             */
/*   Updated: 2017/09/25 17:40:58 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

char			*my_getenv(char *str)
{
	t_env		*env;

	env = gbl_save_env(ENV_REC, NULL);
	if (str)
		while (env)
		{
			if (!ft_strcmp(env->name, str))
				return (env->value);
			else
				env = env->next;
		}
	return (NULL);
}
