/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_dgreat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 16:11:44 by jle-quel          #+#    #+#             */
/*   Updated: 2017/11/19 01:24:23 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

void			jobs_op_dgreat(t_node *node)
{
	int			fildes;

	if ((fildes = open(node->right->content->command[0],
													OPTION_DGREAT, 0644)) != -1)
	{
		if (ft_isdigit(node->content->command[0][0]))
			dup2(fildes, ft_atoi(node->content->command[0]));
		else
			dup2(fildes, STDOUT_FILENO);
		close(fildes);
	}
	else
		check_path(node->right->content->command[0]);
}

uint8_t			op_dgreat(t_node *node, t_jobs *jobs, int info)
{
	t_process	*process;

	log_debug("VALUE DGREAT %d", info);
	if (info & FORK)
	{
		if ((jobs = new_jobs(jobs)) == NULL)
			return (var_return(255));
		process = my_fork(jobs, find_executing_node(node), info);
		if (process->pid)
			my_wait(jobs);
		else
		{
			process->pid = getpid();
			jobs_op_dgreat(node);
			execute_node(node->left, jobs, info ^ FORK);
		}
	}
	else
	{
		jobs_op_dgreat(node);
		execute_node(node->left, jobs, info);
	}
	return (1);
}
