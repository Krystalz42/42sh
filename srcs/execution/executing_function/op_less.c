/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_less.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 16:16:43 by jle-quel          #+#    #+#             */
/*   Updated: 2017/11/19 01:18:52 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

static void		jobs_op_less(t_node *node)
{
	int			fildes;

	if ((fildes = open(node->right->content->command[0], O_RDONLY)) == -1)
		check_path(node->right->content->command[0]);
	dup2(fildes, STDIN_FILENO);
	close(fildes);
}

uint8_t			op_less(t_node *node, t_jobs *jobs, int info)
{
	t_process	*process;

	log_debug("VALUE_LESS %d", info);
	if (info & FORK)
	{
		if ((jobs = new_jobs(jobs)) == NULL)
			return (var_return(255));
		process = my_fork(jobs, find_executing_node(node), info);
		if (jobs->process->pid > 0)
			my_wait(jobs);
		else
		{
			process->pid = getpid();
			jobs_op_less(node);
			execute_node(node->left, jobs, info ^ FORK);
		}
	}
	else
	{
		jobs_op_less(node);
		execute_node(node->left, jobs, info);
	}
	return (var_return(-1));
}
