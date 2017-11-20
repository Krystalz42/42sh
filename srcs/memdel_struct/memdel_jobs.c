/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memdel_jobs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelazou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 11:55:12 by sbelazou          #+#    #+#             */
/*   Updated: 2017/11/19 11:55:36 by sbelazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

static void		reset_process(t_jobs **jobs)
{
	t_process	*process;

	while ((*jobs)->process)
	{
		process = (*jobs)->process;
		(*jobs)->process = (*jobs)->process->next;
		ft_memdel((void **)&process->command);
		ft_memdel((void **)&process);
	}
	ft_memdel((void **)jobs);
}

static void		connect_use(t_jobs *jobs)
{
	if (jobs->next_use)
		jobs->next_use->prev_use = jobs->prev_use;
	if (jobs->prev_use)
		jobs->prev_use->next_use = jobs->next_use;
}

void			memdel_jobs(t_jobs *jobs)
{
	t_jobs		*addr_jobs;

	addr_jobs = jobs_table(REC_STRUCT);
	connect_use(jobs);
	ft_dprintf(fd_log, "addr_index [%d] jobs index [%d]\n",addr_jobs->index, jobs->index);
	if (addr_jobs && addr_jobs->index == jobs->index)
	{
		jobs_table(REC_STRUCT);
		ft_dprintf(fd_log, " IN MEMDEL_JOBS [addr_jobs == jobs] %d\n", jobs_table(REC_STRUCT) ? 1 : 0);
	}
	else
	{
		if (jobs->next)
			jobs->next->prev = jobs->prev;
		if (jobs->prev)
			jobs->prev->next = jobs->next;
		reset_process(&jobs);
	}
}
