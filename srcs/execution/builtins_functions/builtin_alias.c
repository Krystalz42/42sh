/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_alias.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 15:57:47 by jle-quel          #+#    #+#             */
/*   Updated: 2017/12/20 15:14:21 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

/*
*************** PRIVATE ********************************************************
*/

static uint8_t	alias_fct(char **command, int options)
{
	if (options & 1)
		return (remove_alias(command));
	else if (options & 2)
		return (append_alias(command));
	else if (options & 4)
		return (append_rc(command));
	else if (command && *command)
		return (interactive_alias(command));
	else
		return (print_alias(STDOUT_FILENO, DEFAULT));
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
			if (potential_option("-crw", command[index][table]) == 0)
				return (error_msg(ALIAS, BAD_OPTION, command[index] + table));
			options += command[index][table] == 'c' && !(options & 1) ? 1 : 0;
			options += command[index][table] == 'r' && !(options & 2) ? 2 : 0;
			options += command[index][table] == 'w' && !(options & 4) ? 4 : 0;
			table++;
		}
		index++;
	}
	return (var_return(alias_fct(command + index, options)));
}

/*
*************** PUBLIC *********************************************************
*/

uint8_t			builtin_alias(t_parsing *node, int info)
{
	(void)info;
	return (check_options_alias(node->command));
}
