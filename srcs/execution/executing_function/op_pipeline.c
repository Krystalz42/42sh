/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_pipeline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 16:11:51 by jle-quel          #+#    #+#             */
/*   Updated: 2017/11/19 04:26:06 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

/*
*************** PRIVATE ********************************************************
*/

/*
*************** PUBLIC *********************************************************
*/

uint8_t			op_pipeline(t_node *node, t_jobs *jobs, int info)
{
	int			fildes[2];		
	t_process	*process;


	log_debug("PIPELINE,	info: [%d]", info);
	jobs = new_jobs(jobs);
	pipe(fildes);
	process = my_fork(jobs, find_executing_node(node), info);
	process->fildes[0] = fildes[0];
	process->fildes[1] = fildes[1];
	if (process->pid)
		execute_node(node->left, jobs, (info | WRITE_PREVIOUS) | FORCE_FORK);
	else
	{
		process->pid = getpid();
		read_pipe(fildes);
		log_info("FIRST SON		info: [%d]", info);
		if (info & WRITE_PREVIOUS)
		{
			log_info("SON INSIDE IF		info: [%d]", info);
			write_pipe(process->prev->fildes);
		}
		execute_node(node->right, jobs, info ^ FORK);
	}
	return (1);
}
