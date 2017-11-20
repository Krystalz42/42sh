/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_dgreat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 16:11:44 by jle-quel          #+#    #+#             */
/*   Updated: 2017/11/20 23:38:46 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

/*
*************** PRIVATE ********************************************************
*/

static void		jobs_op_dgreat(t_node *node)
{
	int			std;
	int			fildes;

	std = STDOUT_FILENO;
	if (ft_isdigit(node->content->command[0][0]))
		std = ft_atoi(node->content->command[0]);
	if ((fildes = open(node->right->content->command[0],
				OPTION_DGREAT, 0644)) == -1)
		check_path(node->right->content->command[0]);
	else
	{
		fildes = check_fd(fildes);
		dup2(fildes, std);
		close(fildes);
	}
}

/*
*************** PUBLIC *********************************************************
*/

uint8_t			op_dgreat(t_node *node, t_jobs *jobs, int info)
{
	t_process	*process;

	if (info & FORK)
	{
		jobs = new_jobs(jobs);
		if ((process = my_fork(jobs, find_executing_node(node), info)) == NULL)
			return (var_return(255));
		if (process->pid)
			my_wait(jobs);
		else
		{
			process->pid = getpid();
			jobs_op_dgreat(node);
			execute_node(node->left, jobs, (info ^ FORK));
		}
	}
	else
	{
		jobs_op_dgreat(node);
		execute_node(node->left, jobs, info);
	}
	return (var_return(-1));
}
