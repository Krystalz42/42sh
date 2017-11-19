/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_execution.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 15:20:55 by jle-quel          #+#    #+#             */
/*   Updated: 2017/11/19 10:48:06 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

uint8_t					exec_or_builtin(t_node *node, int info)
{
	if (check_if_builtin(node, info) == -1)
		my_execve(node->content->command, get_real_env(node));
	else
		exit(var_return(-1));
	return (var_return(-1));
}

uint8_t					jobs_execution(t_node *node, t_jobs *jobs, int info)
{
	t_process		*process;

	log_debug("VALUE_EXECUTION %d", info);
	if (info & FORK)
	{
		jobs = new_jobs(jobs);
		if ((process = my_fork(jobs, node, info)) == NULL)
			return (var_return(255));
		if (process->pid > 0)
		{
			my_wait(jobs);
		}
		else if (process->pid == 0)
		{
			process->pid = getpid();
			if (info & WRITE_PREVIOUS && process && process->prev)
				write_pipe(process->prev->fildes);
			exec_or_builtin(node,  info);
		}
	}
	else
	{
		process = get_process(getpid());
		if (info & WRITE_PREVIOUS && process && process->prev)
			write_pipe(process->prev->fildes);
		exec_or_builtin(node, info);
	}
	return (var_return(-1));
}

uint8_t					op_execution(t_node *node, t_jobs *jobs, int info)
{
	if (info & FORCE_FORK || !(info & FORK))
		jobs_execution(node, jobs, info);
	else if (check_if_builtin(node, info) == -1)
		jobs_execution(node, jobs, info);
	return (var_return(-1));
}
