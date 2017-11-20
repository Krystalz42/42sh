/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_use.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelazou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 15:40:31 by sbelazou          #+#    #+#             */
/*   Updated: 2017/11/20 15:40:34 by sbelazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

t_jobs			*add_next_use(t_jobs *new)
{
	t_jobs		*jobs;

	jobs = *jobs_table();
	while (jobs && jobs->next_use)
		jobs = jobs->next_use;
	if (jobs && jobs != new)
	{
		new->prev_use = jobs;
		jobs->next_use = new;
	}
	return (new);
}
