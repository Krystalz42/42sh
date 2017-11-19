/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <aroulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 18:56:57 by aroulin           #+#    #+#             */
/*   Updated: 2017/11/19 01:28:59 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

int					finished_process(t_process *process)
{
	while (process)
	{
		if (process->finished == 0)
			return (0);
		process = process->next;
	}
	return (1);
}

void					update_status(t_process *process)
{
	while (process)
	{
		if (WIFEXITED(process->status) || WIFSIGNALED(process->status))
			process->finished = 1;
		process = process->next;
	}
}

void				close_fildes(t_process *process)
{
	while (process->next)
	{
		close_pipe(process->fildes);
		process = process->next;
	}
}
