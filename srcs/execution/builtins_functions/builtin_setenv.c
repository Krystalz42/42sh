/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelazou <sbelazou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 17:36:39 by sbelazou          #+#    #+#             */
/*   Updated: 2017/11/15 20:14:39 by sbelazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

uint8_t			builtin_setenv(t_node *node, int info __attribute__((unused)))
{
	if (ft_strchr(node->content->command[1], '='))
	{
		if (node->content->command[1][0] != '=')
		{
			if (my_getenv(node->content->command[1]))
			{
				remove_environment(node->content->command[1]);
				add_environment(node->content->command[1]);
			}
			else
				add_environment(node->content->command[1]);
			return (var_return(0));
		}
		else
		{
			error_msg(SETENV, NEED_VALUE, node->content->command[1]);
			return (var_return(usage_setenv() + 1));
		}
	}
	else
	{
		error_msg(SETENV, WRONG_FORMAT, node->content->command[1]);
		return (var_return(usage_setenv() + 1));
	}
}
