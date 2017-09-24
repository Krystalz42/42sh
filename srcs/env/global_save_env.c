/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_save_env.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 23:23:46 by aroulin           #+#    #+#             */
/*   Updated: 2017/09/23 19:46:10 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

t_env		*gbl_save_env(unsigned short flags, t_env *env)
{
	static t_env *save;

	if ((flags & ENV_NULL))
		save = NULL;
	else if ((flags & ENV_INIT))
		save = env;
	else if ((flags & ENV_REC))
		;
	return (save);
}
