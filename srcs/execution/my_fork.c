/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 15:19:04 by jle-quel          #+#    #+#             */
/*   Updated: 2017/11/19 04:26:58 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

t_process		*new_process(t_jobs *jobs)
{
	t_process	*temp;

	if (jobs->process == NULL)
	{
		jobs->process = (t_process *)ft_memalloc(sizeof(t_process));
		return (jobs->process);
	}
	else
	{
		temp = jobs->process;
		while (temp->next)
			temp = temp->next;
		temp->next = (t_process *)ft_memalloc(sizeof(t_process));
		temp->next->prev = temp;
		return (temp->next);
	}
}

t_process		*my_fork(t_jobs *jobs, t_node *node, int info)
{
	t_process	*process;

	if ((process = new_process(jobs)) == NULL)
		return (NULL);
	if ((process->pid = fork()) == -1)
	{
		error_msg("fork :", "fork failed", NULL);
//		return (NULL);
	}
	log_success("On va attendre les foutu enfants! %d", process->pid);
	process->fildes[0] = -1;
	process->fildes[1] = -1;
	process->running = true;
	process->command = ft_strdup(node->content->input);
	setpgid(process->pid, process->prev ? process->prev->pgid : process->pid);
	process->pgid = getpgid(process->pid);
	process->status = -1;
	process->foreground = (info & FOREGROUND) ? true : false;
	return (process);
}
