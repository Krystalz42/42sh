/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_switch2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelazou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 15:52:59 by sbelazou          #+#    #+#             */
/*   Updated: 2017/11/20 18:45:21 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

int				check_jobs_spec(char **command, char *from)
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
		return (error_msg(from, NO_CUR_JOB, command[table]) - 2);
	else
		jobs_spec = 0;
	return (jobs_spec);
}

t_jobs			*get_jobs_by_setting(int index, char *from)
{
	t_jobs		*jobs;

	if ((jobs = get_real_jobs()) == NULL)
	{
		error_msg(from, NO_CUR_JOB, NULL);
		return (NULL);
	}
	if (index)
	{
		while (jobs)
		{
			if (jobs->index == index)
				return (jobs);
			jobs = jobs->prev_use;
		}
	}
	else
		while (jobs)
		{
			if (from == BG && jobs->process->running == false)
				return (jobs);
			if (from == FG && jobs->process->foreground == false)
				return (jobs);
			jobs = jobs->prev_use;
		}
	error_msg(BG, JOBS_IN_BG, NULL);
	return (NULL);
}
