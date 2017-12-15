/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_execution.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 15:20:55 by jle-quel          #+#    #+#             */
/*   Updated: 2017/11/20 22:43:47 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

void				test(t_parsing *node)
{(void)node;}

t_manage_redir					*g_execute_redir[12] = {
		[VALUE_LESS] = NULL, 		//	POUR TOI
		[VALUE_LESS_AND] = NULL,	//	POUR TOI
		[VALUE_DLESS] = NULL,		//	POUR TOI
		[VALUE_GREAT] = &op_great,		//	POUR MOI
		[VALUE_DGREAT] = &op_dgreat,		//	POUR MOI
		[VALUE_GREAT_AND] = &op_great_and,	//	POUR MOI
};

void				manage_redirection(t_parsing *node)
{
	if (node && node->priority == PRIO_REDIR)
	{
		g_execute_redir[node->value](node);
		manage_redirection(node->next->next);
	}
}

uint8_t				exec_or_builtin(t_node *node, int info)
{
	manage_redirection(node->content->next);
	if (check_if_builtin(node, info) == -1)
		my_execve(node->content->command, get_real_env(node));
	else
		exit(var_return(-1));
	return (var_return(-1));
}

uint8_t				jobs_execution(t_node *node, t_jobs *jobs, int info)
{
	t_process		*process;

	if (info & FORK)
	{
		jobs = new_jobs(jobs);
		if ((process = my_fork(jobs, node, info)) == NULL)
			return (var_return(255));
		if (process->pid > 0)
			my_wait(jobs);
		else if (process->pid == 0)
		{
			process->pid = getpid();
			if (info & WRITE_PREVIOUS && process->prev)
				write_pipe(process->prev->fildes);
			exec_or_builtin(node, info);
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

uint8_t				op_execution(t_node *node, t_jobs *jobs, int info)
{
	if (info & FORCE_FORK || !(info & FORK))
		jobs_execution(node, jobs, info);
	else if (check_if_builtin(node, info) != -1)
		;
	else
		jobs_execution(node, jobs, info);
	return (var_return(-1));
}
