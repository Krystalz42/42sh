/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_jobs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <aroulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 15:22:34 by aroulin           #+#    #+#             */
/*   Updated: 2017/11/20 18:42:58 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

/*
**	-p 1
**		List only the process ID of the job’s process group leader.
**	-r 2
**		Display only running jobs.
**	-s 4
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

static int 		check_jobs(char **command)
{
	int			num;
	int			table;
	t_jobs		*jobs;

	if ((jobs = get_real_jobs()) == NULL)
		return (error_msg(JOBS, JOBS_NOT_FOUND, NULL) - 2);
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
		jobs = jobs->prev_use;
	num = (num == 0 || (jobs && jobs->index == num)) ? num : -1;
	(num == -1) && error_msg(JOBS, JOBS_NOT_FOUND, command[table]);
	return (num);
}

static int		check_option(char **command)
{
	int			ind;
	int			opt;
	int			table;

	opt = 0;
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
			opt += (command[table][ind] == 'p' && !(opt & OPT_P)) ? OPT_P : 0;
			opt += (command[table][ind] == 'r' && !(opt & OPT_R)) ? OPT_R : 0;
			opt += (command[table][ind] == 's' && !(opt & OPT_S)) ? OPT_S : 0;
			opt += (command[table][ind] == 'l' && !(opt & OPT_L)) ? OPT_L : 0;
			ind++;
		}
		table++;
	}
	return (opt);
}

static int		print_jobs(int jobs_spec, int option)
{
	t_jobs		*jobs;
	int			index;

	jobs = jobs_table();
	dprintf(fd_log, "%d\n", jobs_spec);
	if (jobs_spec == 0 && !(index = 0))
	{
		while (CHILD(index))
		{
			if (jobs[index].process)
				print_jobs_info(jobs + index, jobs[index].process, option);
			index++;
		}
	}
	else
	{
		jobs = get_real_jobs();
		while (jobs)
		{
			if (jobs->index == jobs_spec)
				return (print_jobs_info(jobs, jobs->process, option));
			jobs = jobs->prev_use;
		}
	}
	return (0);
}

uint8_t			builtin_jobs(t_node *node, int info)
{
	int			option;
	int			jobs_spec;

	(void)info;
	if ((option = check_option(node->content->command + 1)) == -1)
		return (var_return(-1));
	if ((jobs_spec = check_jobs(node->content->command + 1)) == -1)
		return (1);
	return ((uint8_t)print_jobs(jobs_spec, option));
}
