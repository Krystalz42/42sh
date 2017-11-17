/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fildes_previous.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 15:15:43 by jle-quel          #+#    #+#             */
/*   Updated: 2017/11/17 15:17:18 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

void			close_previous(t_jobs *jobs)
{
	log_debug("Close previous %d", jobs->process->prev ? 1 : 0);
	if (jobs->process->prev)
	{
		close_pipe(jobs->process->prev->fildes);
	}
}

void			read_previous(t_jobs *jobs)
{
	log_debug("Read previous %d", jobs->process->prev ? 1 : 0);
	if (jobs->process->prev)
	{
		read_pipe(jobs->process->prev->fildes);
	}
}

void			write_previous(t_jobs *jobs)
{
	log_debug("Write previous %d", jobs->process->prev ? 1 : 0);
	if (jobs->process->prev)
	{
		log_success("%d %d", jobs->process->prev->fildes[0],
		jobs->process->prev->fildes[1]);
		write_pipe(jobs->process->prev->fildes);
	}
}
