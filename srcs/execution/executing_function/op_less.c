/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_less.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 16:16:43 by jle-quel          #+#    #+#             */
/*   Updated: 2017/12/14 14:07:21 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

/*
*************** PRIVATE ********************************************************
*/

static void		jobs_op_less(t_node *node)
{
	int			std;
	int			fildes;

	if ((fildes = open(node->right->content->command[0], O_RDONLY)) == -1)
		check_path(node->right->content->command[0]);
	else
	{
		std = STDIN_FILENO;
		if (ft_isdigit(node->content->command[0][0]))
			std = ft_atoi(node->content->command[0]);
		dup2(fildes, std);
		close(fildes);
	}
}

/*
*************** PUBLIC *********************************************************
*/

uint8_t			op_less(t_node *node, t_jobs *jobs, int info)
{
	t_process	*process;

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
			if (process->prev)
				write_pipe(process->prev->fildes);
			jobs_op_less(node);
			execute_node(node->left, jobs, (info ^ FORK) ^ WRITE_PREVIOUS);
		}
	}
	else
	{
		jobs_op_less(node);
		execute_node(node->left, jobs, info);
	}
	return (var_return(-1));
}
