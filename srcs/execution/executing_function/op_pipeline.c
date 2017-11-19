/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_pipeline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 16:11:51 by jle-quel          #+#    #+#             */
/*   Updated: 2017/11/19 23:42:43 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

/*
*************** PUBLIC *********************************************************
*/

uint8_t			op_pipeline(t_node *node, t_jobs *jobs, int info)
{
	int			fildes[2];
	t_process	*process;

	jobs = new_jobs(jobs);
	pipe(fildes);
	if ((process = my_fork(jobs, find_executing_node(node), info)) == NULL)
		return (var_return(255));
	process->fildes[0] = fildes[0];
	process->fildes[1] = fildes[1];
	if (process->pid)
		execute_node(node->left, jobs, (info | WRITE_PREVIOUS) | FORCE_FORK);
	else
	{
		process->pid = getpid();
		read_pipe(fildes);
		if (info & WRITE_PREVIOUS)
			write_pipe(process->prev->fildes);
		execute_node(node->right, jobs, info ^ FORK);
	}
	return (1);
}
