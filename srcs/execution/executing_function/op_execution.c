/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_execution.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 15:20:55 by jle-quel          #+#    #+#             */
/*   Updated: 2017/12/16 17:32:35 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

t_manage_redir		*g_execute_redir[14] =
{
		[VALUE_LESS] = &op_less,
		[VALUE_LESS_AND] = &op_less_and,
		[VALUE_DLESS] = &op_dless,
		[VALUE_GREAT] = &op_great,
		[VALUE_DGREAT] = &op_dgreat,
		[VALUE_GREAT_AND] = &op_great_and,
		[VALUE_STRING] = &op_string,
		[VALUE_LESSGREAT] = &op_lessgreat,
};

int					manage_redirection(t_parsing *node)
{
	if (node && node->priority == PRIO_REDIR)
	{
		if ((g_execute_redir[node->value](node)) == 1)
			manage_redirection(node->next->next);
		else
			return (0);
	}
	return (1);
}

uint8_t				exec_or_builtin(t_parsing *node, int info)
{
	if ((manage_redirection(node->next)) == 0)
		exit(1);
	if (check_if_builtin(node, info) == -1)
		my_execve(node->command, get_real_env(node));
	else
		exit(var_return(-1));
	return (var_return(-1));
}

uint8_t				jobs_execution(t_parsing *node, t_jobs *jobs, int info)
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

uint8_t				op_execution(t_parsing *node, t_jobs *jobs, int info)
{
	if (jobs || (node->next && node->next->priority == PRIO_REDIR))
		return (jobs_execution(node, jobs, info));
	if (check_if_builtin(node, info) != -1)
		;
	else
		jobs_execution(node, jobs, info);
	return (var_return(-1));
}
