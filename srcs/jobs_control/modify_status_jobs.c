/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_status_jobs.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 13:41:44 by aroulin           #+#    #+#             */
/*   Updated: 2017/10/12 13:41:46 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

void		modify_runing(t_jobs *jobs, int change)
{
	int			index;

	index = 0;
	while (jobs)
	{
		change++;
		index++;
	}
}

void		modify_foreground(t_jobs *jobs, int change)
{
	int index;

	index = 0;
	while (jobs)
	{
		change++;
		index++;
	}
}