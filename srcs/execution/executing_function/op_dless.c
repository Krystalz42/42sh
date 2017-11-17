/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_dless.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 16:14:51 by jle-quel          #+#    #+#             */
/*   Updated: 2017/11/17 16:14:53 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

void					intro_heredoc(t_node *node)
{
	int				fildes;

	fildes = open(node->content->heredoc, O_RDONLY);
	dup2(fildes, STDIN_FILENO);
	close(fildes);
	remove(node->content->heredoc);
}

uint8_t					op_dless(t_node *node, t_jobs *jobs, int info)
{
	log_debug("VALUE_DLESS %d", info);
	if (info & FORK)
	{
		if ((jobs = new_jobs(jobs)) == NULL)
			return (var_return(255));
		jobs->process = my_fork(jobs, find_executing_node(node), info);
		if (jobs->process->pid > 0)
		{
			my_wait(jobs);
		}
		else
		{
			jobs->process->pid = getpid();
			intro_heredoc(node);
			execute_node(node->left, jobs, info ^ FORK);
		}
	}
	else
	{
		intro_heredoc(node);
		execute_node(node->left, jobs, info);
	}
	return (1);
}
