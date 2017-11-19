/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_switch.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <aroulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 15:22:55 by aroulin           #+#    #+#             */
/*   Updated: 2017/11/17 16:15:43 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

int			check_jobs_spec(char **command, char *from)
{
	int			table;
	int			jobs_spec;

	table = 1;
	if (command[table] && command[table][0] == '%')
	{
		if ((jobs_spec = ft_atoi(command[table] + 1)) < 1)
			return (error_msg(from, NO_CUR_JOB, command[table]));
	}
	else if (command[table])
		return (error_msg(from, NO_CUR_JOB, command[table]));
	else
		jobs_spec = 0;
	return (jobs_spec);
}

uint8_t		builtin_foreground(t_node *node, int info)
{
	int			jobs_spec;

	jobs_spec = check_jobs_spec(node->content->command, FG);
	log_success("%d", jobs_spec);
	(void)node;
	(void)info;
	return (error_msg(BG, INVALID, node->content->command[1]));
}

uint8_t		builtin_background(t_node *node, int info)
{
	(void)info;
	(void)node;
	return (error_msg(BG, INVALID, node->content->command[1]));
}
