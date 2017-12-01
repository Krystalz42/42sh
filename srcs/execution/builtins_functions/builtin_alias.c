/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_alias.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 15:57:47 by jle-quel          #+#    #+#             */
/*   Updated: 2017/12/01 19:09:12 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

/*
*************** PRIVATE ********************************************************
*/

static uint8_t	alias_fct(char **command, int options)
{
	if (options & 1)
		return (remove_alias());
	else if (command && *command)
		return (interactive_alias(command));
	else
		return (print_alias());
}

static int		check_options_alias(char **command)
{
	uint8_t		options;
	size_t		index;
	size_t		table;

	options = 0;
	index = 1;
	while (command[index] && command[index][0] == '-')
	{
		if (ft_strcmp("--help", command[1]) == 0)
			return (var_return(usage_alias()));
		table = 0;
		while (command[index][table])
		{
			if (potential_option("-cdrw", command[index][table]) == 0)
				return (error_msg(HISTORY, BAD_OPTION, command[index] + table));
			options += command[index][table] == 'c' && !(options & 1) ? 1 : 0;
			options += command[index][table] == 'd' && !(options & 2) ? 2 : 0;
			options += command[index][table] == 'r' && !(options & 4) ? 4 : 0;
			options += command[index][table] == 'w' && !(options & 8) ? 8 : 0;
			table++;
		}
		index++;
	}
	return (var_return(alias_fct(command + index, options)));
}

/*
*************** PUBLIC *********************************************************
*/

uint8_t			builtin_alias(t_node *node, int info __attribute__((unused)))
{
	return (check_options_alias(node->content->command));
}
