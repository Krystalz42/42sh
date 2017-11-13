/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_kill.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 15:22:40 by aroulin           #+#    #+#             */
/*   Updated: 2017/10/30 15:22:42 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>


static uint8_t			kill_option_l(char **command)
{
	if (command[2] && ft_strisdigit(command[2]))
		return (signal_from_int(ft_atoi(command[2])));
	else if (command[2] && ft_strisalpha(command[2] + 1))
		return (signal_from_str(command[2]));
	else
		return (all_signal());
}

uint8_t			builtin_kill(t_node *node, int info __attribute__((unused)))
{
	if (node->content->command[1] && node->content->command[1][0] == '-')
	{
		if (ft_strcmp(node->content->command[1], HELP) == 0)
			return (usage_kill());
		else if (ft_strcmp(node->content->command[1], "-l") == 0)
			return (kill_option_l(node->content->command));
		else if (node->content->command[2])
			return (kill_process(node->content->command[1], node->content->command[2]));
		else
			return (error_msg(KILL, UNKNOWN, node->content->command[1] + 1));
	}
	else if (node->content->command[1])
		return (kill_process(NULL, node->content->command[1]));
	else
		return (error_msg(KILL, NO_ARGS, NULL));
}
