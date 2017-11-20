/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_jobs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 15:12:19 by jle-quel          #+#    #+#             */
/*   Updated: 2017/11/19 11:58:10 by sbelazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

static t_jobs	*create_jobs(void)
{
	t_jobs		**addr_jobs;
	t_jobs		*temp_jobs;

	addr_jobs = jobs_table();
	temp_jobs = *addr_jobs;
	if (*addr_jobs)
	{
		while (temp_jobs->next)
			temp_jobs = temp_jobs->next;
		temp_jobs->next = (t_jobs *)ft_memalloc(sizeof(t_jobs));
		temp_jobs->next->prev = temp_jobs;
		return (temp_jobs->next);
	}
	else
	{
		dprintf(fd_log, "Create from addr\n");
		*addr_jobs = (t_jobs *)ft_memalloc(sizeof(t_jobs));
		return (*addr_jobs);
	}
}

t_jobs			*new_jobs(t_jobs *jobs)
{
	if (jobs == NULL)
	{
		jobs = create_jobs();
		jobs->index = (jobs->prev) ? jobs->prev->index + 1 : 1;
	}
	return (jobs);
}
