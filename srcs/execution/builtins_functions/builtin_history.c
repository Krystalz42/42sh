/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_history.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <aroulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 15:22:26 by aroulin           #+#    #+#             */
/*   Updated: 2017/12/01 17:03:25 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

uint8_t			looking_for_fct(char **command, int option)
{
	if (option & 1)
		return (b_clear_history());
	else if (option & 2)
		return (b_delete_history_offset(ft_atoi(*command)));
	else if (option & 8)
		return (b_write_history_in_file(*command ? ft_strdup(*command) :
								get_str_from_history()));
	else if (option & 4)
		return (write_history_in_sh(*command ? ft_strdup(*command) :
									get_str_from_history()));
	else
		return (b_write_history());
}

int				check_option_history(char **command)
{
	int		option;
	int		table;
	int		index;

	option = 0;
	index = 1;
	while (command[index] && command[index][0] == '-')
	{
		if (!ft_strcmp("--help", command[1]))
			return (var_return(usage_history()));
		table = 0;
		while (command[index][table])
		{
			if (potential_option("-cdrw", command[index][table]) == 0)
				return (error_msg(HISTORY, BAD_OPTION, command[index] + table));
			option += command[index][table] == 'c' && !(option & 1) ? 1 : 0;
			option += command[index][table] == 'd' && !(option & 2) ? 2 : 0;
			option += command[index][table] == 'r' && !(option & 4) ? 4 : 0;
			option += command[index][table] == 'w' && !(option & 8) ? 8 : 0;
			table++;
		}
		index++;
	}
	return (var_return(looking_for_fct(command + index, option)));
}

uint8_t			builtin_history(t_node *node, int info)
{
	(void)info;
	return (check_option_history(node->content->command));
}
