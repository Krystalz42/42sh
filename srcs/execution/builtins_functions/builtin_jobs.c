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
*/

int				print_process(t_process process, int info, int parent, int index)
{
	if (process.pid == process.pgid)
		ft_printf("[%d]\t", index + 1);
	else if (parent && process.pid != process.pgid)
		return (1);
	else
		ft_putchar('\t');
	if (info)
		ft_printf("\t%d %d %s %s\n", process.pid, process.pgid,
				process.running ? RUN : STOP, process.command);
	else
		ft_printf("\t%s %s\n", process.running ? RUN : STOP, process.command);
	return (1);
}

uint8_t			print_jobs(t_jobs *jobs, int opt)
{
	int			i;
	int			ind_c;

	i = 0;
	while (i < MAX_CHILD)
	{
		ind_c = 0;
		while (jobs[i].process[ind_c].pid)
		{
			if ((opt & 2) && jobs[i].process[ind_c].running)
				print_process(jobs[i].process[ind_c], (opt & 8), (opt & 1), i);
			else if ((opt & 4) && jobs[i].process[ind_c].running == false)
				print_process(jobs[i].process[ind_c], (opt & 8), (opt & 1), i);
			else if (!(opt & 2) && !(opt & 4))
				print_process(jobs[i].process[ind_c], (opt & 8), (opt & 1), i);
			ind_c++;
		}
		i++;
	}
	return (0);
}

uint8_t			builtin_jobs(t_node *node, int info)
{
	int					table;
	int					opt;
	int					index;

	(void)info;
	opt = 0;
	table = 1;
	if (node->content->command[1] && ft_strcmp(node->content->command[1], HELP) == 0)
		return (var_return(usage_jobs()));
	while (node->content->command[table] && node->content->command[table][0] == '-')
	{
		index = 0;
		while (node->content->command[table][index])
		{
			opt += (node->content->command[table][index] == 'p' && !(opt & 1)) ? 1 : 0;
			opt += (node->content->command[table][index] == 'r' && !(opt & 2)) ? 2 : 0;
			opt += (node->content->command[table][index] == 's' && !(opt & 4)) ? 4 : 0;
			opt += (node->content->command[table][index] == 'l' && !(opt & 8)) ? 8 : 0;
			index++;
		}
		table++;
	}
	log_trace("Jobs [%d]", opt);
	return (var_return(print_jobs(jobs_table(), opt)));
}
