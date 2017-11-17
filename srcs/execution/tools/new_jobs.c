/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_jobs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 15:12:19 by jle-quel          #+#    #+#             */
/*   Updated: 2017/11/17 15:12:21 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

t_jobs				*new_jobs(t_jobs *jobs)
{
	int			index;

	if (jobs == NULL)
	{
		index = MAX_CHILD - 1;
		jobs = jobs_table();
		while (index >= 0 && jobs[index].process == NULL)
			index--;
		if (index == MAX_CHILD - 1)
		{
			var_return(255);
			error_msg(S42H, "too much process: ", NULL);
			return (NULL);
		}
		else
		{
			jobs += index + 1;
			jobs->index = index + 2;
			log_debug("jobs [%d] created", index + 1);
			return (jobs);
		}
	}
	return (jobs);
}
