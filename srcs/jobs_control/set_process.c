/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 18:56:57 by aroulin           #+#    #+#             */
/*   Updated: 2017/10/11 18:56:58 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

t_jobs		new_jobs(int set)
{
	t_jobs		to_kill;
	int 		i;

	i = 0;
	ft_memset((void *)&to_kill, set, sizeof(t_jobs));
	while (i < MAX_CHILD)
	{
		i++;
	}
	return (to_kill);
}

void		reset_process(t_process *to_kill)
{
	int 	index;

	index = 0;
	update_jobs(to_kill, 42);
	while (to_kill[index].pid)
	{
		ft_memdel((void **)&(to_kill[index].command));
		to_kill[index] = (t_process){0, 0, 0, 0, 0, NULL};
		index++;
	}
}

int			add_new_child(t_jobs *jobs, t_jobs jobs_id)
{
	int			index;

	index = MAX_CHILD;
	if (index != MAX_CHILD)
	{
		jobs[index + 1] = jobs_id;
		pjt(jobs_id, index + 1);
		return (index + 2);
	}
	else
		return (-1);
}
