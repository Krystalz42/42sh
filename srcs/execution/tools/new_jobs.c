/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_jobs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 15:12:19 by jle-quel          #+#    #+#             */
/*   Updated: 2017/11/20 23:30:34 by jle-quel         ###   ########.fr       */
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
	if (index == MAX_CHILD - 1 && jobs[index].process)
		return (NULL);
	jobs[index + 1].index = index + 2;
	return (jobs + (index + 1));
}

t_jobs			*new_jobs(t_jobs *jobs)
{
	t_jobs		*use;

	if (jobs == NULL)
	{
		use = get_real_jobs();
		jobs = create_jobs();
		if (use)
		{
			while (use->next_use)
				use = use->next_use;
			use->next_use = jobs;
			jobs->prev_use = use;
		}
	}
	return (jobs);
}
