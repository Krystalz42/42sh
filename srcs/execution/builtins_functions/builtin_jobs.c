/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_jobs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 15:22:34 by aroulin           #+#    #+#             */
/*   Updated: 2017/10/30 15:22:36 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

/*
**	-p 1
**		List only the process ID of the job’s process group leader.
**	-r 2
**		Display only running jobs.
**	s 4
**		Display only STOP jobs.
**	-l 8
**		List process IDs in addition to the normal information.
**	16
**		Force Continued
*/

static uint8_t			jobs_iter(t_jobs *jobs, int option)
{
	int					index;

	index = 0;
	while (index < MAX_CHILD)
	{
		if (jobs[index].process)
			print_jobs(jobs + index, option);
		index++;
	}
	return (0);
}

static int				check_option(char **command)
{
	int			index;
	int			option;
	int			table;

	option = 0;
	table = 1;
	if (command[table] && ft_strcmp(command[table], HELP) == 0)
		return (var_return(usage_jobs()) - 1);
	while (command[table] && command[table][0] == '-')
	{
		index = 1;
		while (command[table][index])
		{
			if (potential_option("prsl", command[index][table]) == 0)
				return (error_msg(JOBS, BAD_OPTION, command[table] + index));
			option += (command[table][index] == 'p' && !(option & 1)) ? 1 : 0;
			option += (command[table][index] == 'r' && !(option & 2)) ? 2 : 0;
			option += (command[table][index] == 's' && !(option & 4)) ? 4 : 0;
			option += (command[table][index] == 'l' && !(option & 8)) ? 8 : 0;
			index++;
		}
		table++;
	}
	return (option);
}

static int				check_jobs_spec(char **command)
{
	int			table;
	int			jobs_spec;

	jobs_spec = 0;
	table = 1;
	while (command[table] && command[table][0] == '-')
		table++;
	if (command[table] && command[table][0] == '%' && ft_strisdigit(command[table] + 1))
		jobs_spec = ft_atoi(command[table] + 1);
	else if (command[table])
		return (-table);
	if (jobs_spec < 0 || jobs_spec > MAX_CHILD)
		return (var_return(error_msg(JOBS, LIMIT, NULL)));
	return (jobs_spec);
}


uint8_t			builtin_jobs(t_node *node, int info __attribute__((unused)))
{
	int					option;
	int					jobs_spec;
	t_jobs				*jobs;

	jobs = jobs_table();
	if ((option = check_option(node->content->command)) > 0)
		return (var_return(-1));
	if ((jobs_spec = check_jobs_spec(node->content->command)) < 0)
		return (error_msg(JOBS, INVALID, node->content->command[ABS(jobs_spec)]));
	if (jobs_spec > 0 && jobs_spec < MAX_CHILD)
		return (var_return(print_jobs(jobs + (jobs_spec - 1), option)));
	return (var_return(jobs_iter(jobs_table(), option)));
}
