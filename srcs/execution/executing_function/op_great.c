/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_great.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 15:19:54 by jle-quel          #+#    #+#             */
/*   Updated: 2017/11/20 19:42:40 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

/*
*************** PRIVATE ********************************************************
*/

static void		jobs_op_great(t_node *node)
{
	int			std;
	int			fildes;

	if ((fildes = open(node->right->content->command[0],
				OPTION_GREAT, 0644)) == -1)
		check_path(node->right->content->command[0]);
	else
	{
		fildes = check_fd(fildes);
		if (ft_strchr(node->content->command[0], '&'))
		{
			dup2(fildes, STDOUT_FILENO);
			dup2(fildes, STDERR_FILENO);
		}
		else
		{
			std = STDOUT_FILENO;
			if (ft_isdigit(node->content->command[0][0]))
				std = ft_atoi(node->content->command[0]);
			dup2(fildes, std);
		}
	}
	close(fildes);
}

/*
*************** PUBLIC *********************************************************
*/

uint8_t			op_great(t_node *node, t_jobs *jobs, int info)
{
	t_process	*process;

	ft_dprintf(fd_log, "VALUE OP_GREAT [%d]\n", info);
	if (info & FORK)
	{
		jobs = new_jobs(jobs);
		if ((process = my_fork(jobs, find_executing_node(node), info)) == NULL)
			return (var_return(255));
		if (process->pid > 0)
			my_wait(jobs);
		else
		{
			process->pid = getpid();
			jobs_op_great(node);
			execute_node(node->left, jobs, (info ^ FORK));
		}
	}
	else
	{
		jobs_op_great(node);
		execute_node(node->left, jobs, info);
	}
	return (var_return(-1));
}
