/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_execution.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 15:20:55 by jle-quel          #+#    #+#             */
/*   Updated: 2017/11/17 15:21:07 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

static void				jobs_execution(t_node *node, int info)
{
	if (check_if_builtin(node, info) >= 0)
		exit(var_return(-1));
	else
		my_execve(node->content->command, get_real_env(node));
}

static void				do_execution(t_node *node, t_jobs *jobs, int info)
{
	t_process		*process;

	if (FORK & info)
	{
		if ((jobs = new_jobs(jobs)) == NULL)
			return ;
		process = my_fork(jobs, node, info);
		if (process->pid > 0)
		{
			log_success("On va wait les enfants!");
			my_wait(jobs);
		}
		else if (process->pid == 0)
		{
			process->pid = getpid();
			if (process->prev)
				write_pipe(process->prev->fildes);
			jobs_execution(node, info);
		}
	}
	else
	{
		jobs_execution(node, info);
	}
}

uint8_t					op_execution(t_node *node, t_jobs *jobs, int info)
{
	log_debug("VALUE_EXECUTION %d", info);
	if (check_if_builtin(node, info | DONT_EXECUTE) >= 0 &&
			!(info & FORCE_FORK) && (info & FORK))
		check_if_builtin(node, info);
	else
		do_execution(node, jobs, info);
	return (var_return(-1));
}
