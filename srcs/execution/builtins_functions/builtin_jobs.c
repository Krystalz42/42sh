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

int			print_process(t_process *process, int info, int parent, int index)
{
	if (process->pid == process->pgid)
		ft_printf("[%d]\t", index + 1);
	else if (parent && process->pid != process->pgid)
		return (1);
	else
		ft_putchar('\t');
	if (info)
		ft_printf("\t%d %d %s %s\n", process->pid, process->pgid,
				process->running ? RUN : STOP, process->command);
	else
		ft_printf("\t%s %s\n", process->running ? RUN : STOP, process->command);
	return (1);
}

uint8_t		print_jobs(t_jobs *jobs, int opt)
{
	int					index;
	t_process			*process;

	index = 0;
	while (index < MAX_CHILD)
	{
		if (jobs[index].process)
		{
			process = jobs[index].process;
			while (process)
			{
				if ((opt & 2) && process->running)
					print_process(process, (opt & 8), (opt & 1), index);
				else if ((opt & 4) && process->running == false)
					print_process(process, (opt & 8), (opt & 1), index);
				else if (!(opt & 2) && !(opt & 4))
					print_process(process, (opt & 8), (opt & 1), index);
				process = process->next;
			}
		}
		index++;
	}
	return (0);
}

uint8_t			builtin_jobs(t_node *node, int info __attribute__((unused)))
{
	int					t;
	int					opt;
	int					i;

	opt = 0;
	t = 1;
	if (node->content->command[1] && !ft_strcmp(node->content->command[1], HELP))
		return (var_return(usage_jobs()));
	while (node->content->command[t] && node->content->command[t][0] == '-')
	{
		i = 0;
		while (node->content->command[t][i])
		{
			opt += (node->content->command[t][i] == 'p' && !(opt & 1)) ? 1 : 0;
			opt += (node->content->command[t][i] == 'r' && !(opt & 2)) ? 2 : 0;
			opt += (node->content->command[t][i] == 's' && !(opt & 4)) ? 4 : 0;
			opt += (node->content->command[t][i] == 'l' && !(opt & 8)) ? 8 : 0;
			i++;
		}
		t++;
	}
	return (var_return(print_jobs(jobs_table(), opt)));
}
