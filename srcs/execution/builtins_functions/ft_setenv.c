/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelazou <sbelazou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 17:36:39 by sbelazou          #+#    #+#             */
/*   Updated: 2017/10/28 17:05:12 by sbelazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>



uint8_t					ft_setenv(t_node *node, int inf __attribute__((unused)))
{
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
