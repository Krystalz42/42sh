//
// Created by Alexandre ROULIN on 11/10/17.
//

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