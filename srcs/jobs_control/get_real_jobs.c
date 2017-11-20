/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_real_jobs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelazou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 22:44:04 by sbelazou          #+#    #+#             */
/*   Updated: 2017/11/20 22:44:17 by sbelazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

t_jobs		*get_real_jobs(void)
{
	t_jobs		*jobs;
	int			index;

	index = 0;
	jobs = jobs_table();
	while (CHILD(index))
	{
		if (jobs[index].process)
		{
			jobs += index;
			while (jobs->next_use)
			{
				jobs = jobs->next_use;
			}
			return (jobs);
		}
		index++;
	}
	return (NULL);
}
