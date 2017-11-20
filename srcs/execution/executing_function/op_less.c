/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_less.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 16:16:43 by jle-quel          #+#    #+#             */
/*   Updated: 2017/11/20 22:42:57 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

/*
*************** PRIVATE ********************************************************
*/

void			jobs_op_less(t_node *node)
{
	int			fildes;

	if ((fildes = open(node->right->content->command[0], O_RDONLY)) == -1)
		check_path(node->right->content->command[0]);
	else
	{
		dup2(fildes, STDIN_FILENO);
		close(fildes);
	}
}

static int		norminette(int info, int fildes)
{
	write_pipe(fildes);
	info ^= WRITE_PREVIOUS;
	return (info);
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
		if (process->pid)
			my_wait(jobs);
		else
		{
			process->pid = getpid();
			jobs_op_less(node);
			if (process->prev)
				info = norminette(info, process->prev->fildes);
			execute_node(node->left, jobs, (info ^ FORK));
		}
	}
	else
	{
		jobs_op_less(node);
		execute_node(node->left, jobs, info);
	}
	return (var_return(-1));
}
