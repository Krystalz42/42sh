/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_jobs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <aroulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 15:22:34 by aroulin           #+#    #+#             */
/*   Updated: 2017/11/18 12:01:23 by jle-quel         ###   ########.fr       */
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

/*
**	check option
**
**	-1 error [No jobs at current index]
**
**	0 Print all jobs [No index have been specified]
**
**	> 0 Print jobs currently specified
**
*/
static int 				check_jobs(char **command)
{
	int			num;
	int			table;
	t_jobs		*jobs;

	jobs = *jobs_table();
	table = 0;
	while (command[table] && command[table][0] == '-')
		table++;
	if ((command[table] && command[table][0] == '%'))
	{
		if ((num = ft_atoi(command[table] + 1)) < 1)
			return (error_msg(JOBS, JOBS_NOT_FOUND, command[table]) - 2);
	}
	else if (command[table])
		return (error_msg(JOBS, JOBS_NOT_FOUND, command[table]) - 2);
	else
		num = 0;
	while (num != 0 && jobs && jobs->index != num)
		jobs = jobs->next;
	num = (num == 0 || (jobs && jobs->index == num)) ? num : -1;
	(num == -1) && error_msg(JOBS, JOBS_NOT_FOUND, command[table]);
	return (num);
}

static int				check_option(char **command)
{
	int			ind;
	int			option;
	int			table;

	option = 0;
	table = 0;
	if (command[table] && ft_strcmp(command[table], HELP) == 0)
		return (var_return(usage_jobs()) - 1);
	while (command[table] && command[table][0] == '-')
	{
		ind = 0;
		while (command[table][ind])
		{
			if (potential_option("p-rsl", command[table][ind]) == 0)
				return (error_msg(JOBS, BAD_OPTION, command[table] + ind) - 2);
			option += (command[table][ind] == 'p' && !(option & 1)) ? 1 : 0;
			option += (command[table][ind] == 'r' && !(option & 2)) ? 2 : 0;
			option += (command[table][ind] == 's' && !(option & 4)) ? 4 : 0;
			option += (command[table][ind] == 'l' && !(option & 8)) ? 8 : 0;
			ind++;
		}
		table++;
	}
	return (option);
}

static int					print_jobs(int jobs_spec, int option)
{
	t_jobs		*jobs;

	jobs = *jobs_table();
	if (jobs_spec == 0)
	{
		while (jobs)
		{
			print_jobs_info(jobs, option);
			jobs = jobs->next;
		}
	}
	else
	{
		while (jobs->index != jobs_spec)
			jobs = jobs->next;
		print_jobs_info(jobs, option);
	}
	return (0);
}

uint8_t					builtin_jobs(t_node *node, int info)
{
	int			option;
	int			jobs_spec;

	(void)info;
	if ((option = check_option(node->content->command + 1)) == -1)
		return (1);
	if ((jobs_spec = check_jobs(node->content->command + 1)) == -1)
		return (1);
	return (print_jobs(jobs_spec, option));
}
