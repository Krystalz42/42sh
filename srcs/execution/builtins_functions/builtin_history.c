/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_history.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 15:22:26 by aroulin           #+#    #+#             */
/*   Updated: 2017/10/30 15:22:28 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

static int		potential_option(int c)
{
	static const char		potential[] = "cdrw";
	int						index;

	index = 0;
	while (potential[index])
	{
		if (potential[index] == c)
			return (1);
		index++;
	}
	return (0);
}

uint8_t			looking_for_fct(char **command, int option)
{
	log_trace("%s, %d", *command, option);
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

uint8_t			builtin_history(t_node *node, int info)
{
	int			option;
	int			index;
	int			c;

	(void)info;
	option = 0;
	index = 1;
	while (node->content->command[index] && node->content->command[index][0] == '-')
	{
		if (!ft_strcmp("--help", node->content->command[1]))
			return (var_return(usage_history()));
		c = 1;
		while (node->content->command[index][c])
		{
			if (potential_option(node->content->command[index][c]) == 0)
				return (error_msg(HISTORY, INVALID, node->content->command[index] + c));
			option += node->content->command[index][c] == 'c' && !(option & 1) ? 1 : 0;
			option += node->content->command[index][c] == 'd' && !(option & 2) ? 2 : 0;
			option += node->content->command[index][c] == 'r' && !(option & 4) ? 4 : 0;
			option += node->content->command[index][c] == 'w' && !(option & 8) ? 8 : 0;
			c++;
		}
		index++;
	}
	return (looking_for_fct(node->content->command + index, option));
}
