/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memdel_jobs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelazou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 11:55:12 by sbelazou          #+#    #+#             */
/*   Updated: 2017/11/20 18:44:36 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

static void		reset_process(t_jobs *jobs)
{
	t_process *to_kill;

	while (jobs->process)
	{
		to_kill = jobs->process;
		jobs->process = jobs->process->next;
		ft_memdel((void **)&to_kill->command);
		ft_memdel((void **)&to_kill);

	}
	ft_memset((void *)jobs, 0 , sizeof(t_jobs));
}

//static void		connect_use(t_jobs *jobs)
//{
//	if (jobs->next_use)
//		jobs->next_use->prev_use = jobs->prev_use;
//	if (jobs->prev_use)
//		jobs->prev_use->next_use = jobs->next_use;
//}

void			memdel_jobs(t_jobs *jobs)
{
	t_jobs			*table;
	int				index;

	table = jobs_table();
	index = -1;
	while (++index < MAX_CHILD - 1 && jobs != table)
		table++;
	reset_process(jobs);
	ft_bzero(table, sizeof(t_jobs));
}
