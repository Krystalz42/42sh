/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_use.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelazou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 15:40:31 by sbelazou          #+#    #+#             */
/*   Updated: 2017/11/20 18:38:33 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

t_jobs			*add_next_use(t_jobs *new)
{
	t_jobs		*jobs;
	int			index;

	jobs = jobs_table();
	index = 0;
	while (CHILD(index))
	{
		if (jobs->process && jobs->next_use == NULL)
			break ;
		index++;
	}
	jobs += index;
	return (new);
}
