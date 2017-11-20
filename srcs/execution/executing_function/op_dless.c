/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_dless.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 16:14:51 by jle-quel          #+#    #+#             */
/*   Updated: 2017/11/20 23:31:30 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

/*
*************** PRIVATE ********************************************************
*/

static void		intro_heredoc(t_node *node)
{
	int			fildes;

	fildes = open(node->content->heredoc, O_RDONLY);
	dup2(fildes, STDIN_FILENO);
	close(fildes);
	remove(node->content->heredoc);
}

static int		norminette(int info, int *fildes)
{
	write_pipe(fildes);
	info ^= WRITE_PREVIOUS;
	return (info);
}

/*
*************** PUBLIC *********************************************************
*/

uint8_t			op_dless(t_node *node, t_jobs *jobs, int info)
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
			intro_heredoc(node);
			if (process->prev)
				info = norminette(info, process->prev->fildes);
			execute_node(node->left, jobs, (info ^ FORK));
		}
	}
	else
	{
		intro_heredoc(node);
		execute_node(node->left, jobs, info);
	}
	return (var_return(-1));
}
