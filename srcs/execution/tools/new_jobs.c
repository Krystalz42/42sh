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
	t_jobs		*jobs;
	int			index;

	index = MAX_CHILD - 1;
	jobs = jobs_table();
	while (index >= 0 && jobs[index].process == NULL)
		index--;
	if (index == MAX_CHILD -1 && jobs[index].process)
		return (NULL);
	jobs[index].index = index + 2;
	return (jobs + index);
}

t_jobs			*new_jobs(t_jobs *jobs)
{
	if (jobs == NULL)
		jobs = create_jobs();
	return (jobs);
}
