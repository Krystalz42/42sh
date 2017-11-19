/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_pipeline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 16:11:51 by jle-quel          #+#    #+#             */
/*   Updated: 2017/11/16 16:11:54 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

uint8_t			op_pipeline(t_node *node, t_jobs *jobs, int info)
{
	t_process			*process;

	(void)node; (void)jobs; (void)info;
	log_debug("VALUE_PIPELINE %d", info);
	jobs = new_jobs(jobs);
	process = my_fork(jobs, find_executing_node(node), info);
	if (process->pid)
	{

	}
	else
	{
		process->pid = getpid();
	}
	return (1);
}
