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

void		reset_process(t_process *to_kill)
{
	int 	index;

	index = 0;
	update_jobs(to_kill);
	while (to_kill[index].pid)
	{
		ft_memdel((void **)&(to_kill[index].command));
		to_kill[index] = (t_process){0, 0, 0, 0, 0, NULL};
		index++;
	}
}