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

t_jobs			*add_to_first(t_jobs *new)
{
	t_jobs		*jobs;

	if (new->prev_use)
		new->prev_use->next_use = new->next_use;
	if (new->next_use)
		new->next_use->prev_use = new->prev_use;
	if ((jobs = get_real_jobs()) == NULL)
		return (new);
	new->next_use = NULL;
	jobs->next_use = new;
	new->prev_use = jobs;
	return (new);
}

t_jobs			*add_next_use(t_jobs *new)
{
	t_jobs		*jobs;
	int			index;

	if ((jobs = get_real_jobs()) == NULL)
		;
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
