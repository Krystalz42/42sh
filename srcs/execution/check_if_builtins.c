/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_builtins.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 15:20:09 by aroulin           #+#    #+#             */
/*   Updated: 2017/10/30 15:20:11 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

static const t_builtin	g_builtin[] = {
	(t_builtin){"env", &builtin_env},
	(t_builtin){"setenv", &ft_setenv},
	(t_builtin){"unsetenv", &ft_unsetenv},
	(t_builtin){"cd", &ft_cd},
	(t_builtin){"echo", &ft_echo},
	(t_builtin){"jobs", &builtin_jobs},
	(t_builtin){"history", &builtin_history},
	(t_builtin){"hash", &builtin_hash},
	(t_builtin){"fg", &builtin_foreground},
	(t_builtin){"bg", &builtin_background},
	(t_builtin){"kill", &builtin_kill},
	(t_builtin){"exit", &builtin_exit},
	(t_builtin){"help", &builtin_help},
	(t_builtin){"suspend", &builtin_suspend},
	(t_builtin){NULL, NULL}
};

int				check_if_builtin(t_node *node, int info)
{
	int		index;

	(void)info;
	index = 0;
	while (index < 14)
	{
		if (ft_strcmp(g_builtin[index].str, node->content->command[0]) == 0)
			return (var_return(g_builtin[index].function(node, info)));
		index++;
	}
	return (-1);
}
