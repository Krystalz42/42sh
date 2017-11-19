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

static int			check_jobs_spec(char **command, char *from)
{
	int			table;
	int			jobs_spec;

	table = 1;
	if (command[table] && command[table][0] == '%')
	{
		if ((jobs_spec = ft_atoi(command[table] + 1)) < 1)
			return (error_msg(from, NO_CUR_JOB, command[table]) - 2);
	}
	else if (command[table])
		return (error_msg(from, NO_CUR_JOB, command[table]));
	else
		jobs_spec = 0;
	return (jobs_spec);
}

t_jobs		*get_jobs_by_setting(int index, int foreground, int runing)
{
	t_jobs		*jobs;

	jobs = *jobs_table();
	if (index)
	{
		while (jobs && jobs->index != index)
			jobs = jobs->next;
		if (jobs && jobs->index == index)
			return (jobs);
	}
	else
	{
		while (jobs)
		{
			if (foreground != -1 && jobs->process->foreground != foreground)
			{
				jobs = jobs->next;
				continue ;
			}
			if (foreground != -1 && jobs->process->running != runing)
			{
				jobs = jobs->next;
				continue ;
			}
			return (jobs);
		}
	}
	return (NULL);
}

uint8_t		builtin_foreground(t_node *node, int info)
{
	int			jobs_spec;
	t_jobs		*jobs;

	(void)info;
	if ((jobs_spec = check_jobs_spec(node->content->command, FG)) == -1)
		return (1);
	jobs = get_jobs_by_setting(jobs_spec, false, -1);

	return (0);
}

uint8_t		builtin_background(t_node *node, int info)
{
	(void)info;
	(void)node;
	return (error_msg(BG, INVALID, node->content->command[1]));
}
