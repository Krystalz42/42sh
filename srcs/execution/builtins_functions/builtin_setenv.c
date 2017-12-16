/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_setenv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelazou <sbelazou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 17:36:39 by sbelazou          #+#    #+#             */
/*   Updated: 2017/11/17 16:27:33 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

int				special_getenv(char *string)
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
	if (my_getenv(name))
		remove_environment(name);
	ft_strdel(&name);
	return (ret);
}

uint8_t			builtin_setenv(t_parsing *node, int info)
{
	int			table;

	(void)info;
	table = 0;
	while (node->command[++table])
		if (ft_strchr(node->command[table], '='))
		{
			if (node->command[table][0] != '=')
			{
				special_getenv(node->command[table]);
				add_environment(node->command[table]);
				var_return(0);
			}
			else
			{
				error_msg(SETENV, NEED_VALUE, node->command[table]);
				var_return(1);
			}
		}
		else
		{
			error_msg(SETENV, WRONG_FORMAT, node->command[table]);
			var_return(1);
		}
	return (var_return(var_return(-1) ? usage_setenv() + 1 : 0));
}
