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

void		reset_process(t_jobs *jobs)
{
	t_process		*to_kill;
	if (jobs && jobs->process)
	{
		while (jobs->process && jobs->process->prev)
			jobs->process = jobs->process->prev;
		while (jobs->process)
		{
			to_kill = jobs->process;
			jobs->process = jobs->process->next;
			ft_memdel((void **)&to_kill->command);
			ft_memdel((void **)&to_kill);
		}
	}
	jobs->process = NULL;
}