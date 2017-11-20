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

t_jobs			*iter_jobs(t_jobs *jobs, const char *from)
{
	if (from == BG)
	{
		while (jobs->next_use)
			jobs = jobs->next_use;
		while (jobs)
		{
			if (jobs->process && jobs->process->running == false)
				return (jobs);
		}
	}
	if (from == FG)
	{
		while (jobs->next_use)
			jobs = jobs->next_use;
		return (jobs);
	}
	return (NULL);
}

t_jobs			*get_jobs_by_setting(int index, char *from)
{
	t_jobs		*jobs;

	if ((jobs = get_real_jobs()) == NULL)
		error_msg(from, NO_CUR_JOB, NULL);
	jobs = jobs_table();
		if (CHILD(index) && jobs[index - 1].process == NULL)
		{
			return (NULL);
		}
	if (index == 0)
	{
		index = MAX_CHILD - 1;
		while (CHILD(index) && jobs[index].process == NULL)
			index--;
		return (iter_jobs(jobs + (CHILD(index) ? index : 0), from));
	}
	return (NULL);
}
