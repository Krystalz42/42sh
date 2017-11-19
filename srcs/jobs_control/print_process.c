/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 16:36:56 by jle-quel          #+#    #+#             */
/*   Updated: 2017/11/17 16:38:59 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

int				print_process(t_process *process, int option, int index)
{
	if (process->pid == process->pgid)
		ft_printf("[%d]\t", index);
	else if (option & 1 && process->pid != process->pgid)
		return (1);
	else
		ft_putchar('\t');
	if (option & 8)
		ft_printf("\t%d %d %s %s\n", process->pid, process->pgid,
		process->running ? RUN : STOP, process->command);
	else if (option & 16)
		ft_printf("\t%s %s\n", CONTINUED, process->command);
	else
		ft_printf("\t%s %s\n", process->running ? RUN : STOP, process->command);
	return (1);
}

uint8_t			print_jobs_info(t_jobs *jobs, int option)
{
	t_process			*process;

	process = jobs->process;
	while (process)
	{
		if ((option & 2) && process->running)
			print_process(process, option, jobs->index);
		else if ((option & 4) && process->running == false)
			print_process(process, option, jobs->index);
		else if (!(option & 2) && !(option & 4))
			print_process(process, option, jobs->index);
		process = process->next;
	}
	return (0);
}

void			print_status(t_process *process, int jobs_spec)
{
	(void)jobs_spec;
	cursor_column(1);
	while (process)
	{
		if (process->status != -1)
		{


		}
		process = process->next;
	}
	ioctl(STDIN_FILENO, TIOCSTI, "\0");
}

void			print_info_jobs(t_process *process, int index)
{
	ft_printf("[%d] ", index);
	while (process)
	{
		ft_putnbr(process->pid);
		ft_putchar(32);
		process = process->next;
	}
	ft_putchar(10);
}
