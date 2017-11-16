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

static int		special_getenv(char *string)
{
	char		*name;
	int			index;
	int			ret;

	index = 0;
	while (string[index] && string[index] != '=')
		index++;
	name = (char *)ft_memalloc(sizeof(char) * (index + 1));
	ft_strncpy(name, string, index);
	ret = (my_getenv(name)) ? 1 : 0;
	remove_environment(name);
	ft_strdel(&name);
	return (ret);
}

uint8_t			builtin_setenv(t_node *node, int info __attribute__((unused)))
{
	if (ft_strchr(node->content->command[1], '='))
	{
		if (node->content->command[1][0] != '=')
		{
			special_getenv(node->content->command[1]);
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