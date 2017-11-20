/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 02:24:11 by jle-quel          #+#    #+#             */
/*   Updated: 2017/11/19 12:08:30 by sbelazou         ###   ########.fr       */
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

	jobs = jobs_table(NULL, REC_STRUCT);
	while (jobs)
	{
		process = jobs->process;
		while (process)
		{
			if (pid == process->pid)
				return (process);
			process = process->next;
		}
		jobs = jobs->next;
	}
	return (NULL);
}

t_jobs			*get_jobs(pid_t pgid)
{
	t_jobs		*jobs;

	jobs = jobs_table(NULL, REC_STRUCT);
	while (jobs)
	{
		if (jobs->process->pgid == pgid)
			return (jobs);
		jobs = jobs->next;
	}
	return (NULL);
}
