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
	log_error("%s", my_getenv(node->content->command[1]));
	(void)info;
	if (my_getenv(node->content->command[1]))
	{
		remove_environment(node->content->command[1]);
		return (var_return(0));
	}
	else
	{
		error_msg(UNSETENV, VAR_NO_SET, node->content->command[1]);
		usage_unsetenv();
		return (1);
	}
}
