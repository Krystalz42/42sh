/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 15:15:28 by jle-quel          #+#    #+#             */
/*   Updated: 2017/11/17 15:16:20 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

t_process				*get_process(t_process *process, pid_t pid)
{
	if (process)
	{
		while (process->prev)
			process = process->prev;
		while (process)
		{
			if (process->pid == pid)
				return (process);
			if (pid == -1 && process->next == NULL)
				return (process);
			process = process->next;
		}
	}
	return (NULL);
}
