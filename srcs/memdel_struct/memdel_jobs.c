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

static void		special_memdel(t_jobs **addr_jobs)
{
	t_jobs	*jobs;

	jobs = *addr_jobs;
	*addr_jobs = (*addr_jobs)->next;
	reset_process(&jobs);
	if (*addr_jobs)
		(*addr_jobs)->prev = NULL;
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
	t_jobs		**addr_jobs;
	t_jobs		*temp;

	addr_jobs = jobs_table();
	connect_use(jobs);
	temp = *addr_jobs;
	if (*addr_jobs == jobs)
	{
		special_memdel(addr_jobs);
		dprintf(fd_log, "%s in [%d] > IN MEMDEL_JOBS [addr_jobs == jobs] %d\n", __FILE__, __LINE__, *jobs_table() ? 1 : 0);
	}
	else
		while (temp)
		{
			if (temp == jobs)
			{
				if (temp->prev)
					temp->prev->next = temp->next;
				if (temp->next)
					temp->next->prev = temp->prev;
				reset_process(&temp);
				return ;
			}
			temp = temp->next;
		}
}
