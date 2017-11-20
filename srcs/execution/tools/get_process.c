/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 02:24:11 by jle-quel          #+#    #+#             */
/*   Updated: 2017/11/20 18:46:36 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

/*
*************** PUBLIC *********************************************************
*/

t_process		*get_process(pid_t pid)
{
	t_jobs		*jobs;
	t_process	*process;

	if ((jobs = get_real_jobs()) == NULL)
		return (NULL);
	while (jobs)
	{
		process = jobs->process;
		while (process)
		{
			if (process->pid == pid)
				return (process);
			process = process->next;
		}
		jobs = jobs->prev_use;
	}
	return (NULL);
}

t_jobs			*get_jobs(pid_t pgid)
{
	t_jobs		*jobs;

	if ((jobs = get_real_jobs()) == NULL)
		return (NULL);
	while (jobs)
	{
		if (jobs->process->pgid == pgid)
			return (jobs);
		jobs = jobs->prev_use;
	}
	return (NULL);
}
