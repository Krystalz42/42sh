/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unsetenv.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelazou <sbelazou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 17:36:39 by sbelazou          #+#    #+#             */
/*   Updated: 2017/11/17 16:20:54 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

uint8_t				builtin_unsetenv(t_node *node, int info)
{
	int				table;

	table = 1;
	(void)info;
	while (node->content->command[table])
	{
		if (my_getenv(node->content->command[table]))
		{
			remove_environment(node->content->command[table]);
			var_return(0);
		}
		else
		{
			error_msg(UNSETENV, VAR_NO_SET, node->content->command[table]);
			var_return(1);
		}
		table++;
	}
	return (var_return(var_return(-1) ? usage_unsetenv() + 1 : 0));
}
