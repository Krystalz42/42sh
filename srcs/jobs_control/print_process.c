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



int				print_process(t_jobs *jobs, t_process *process, int option)
{
	(process->prev == NULL) ? ft_printf("[%d]%c\t", jobs->index, (jobs->next_use == NULL && process->pid == process->pgid) ? '+' : '\0') : ft_putstr("\t");
	if (option & OPT_C)
		return (ft_printf("%d %s %s\n", process->pid, CONTINUED, process->command));
	if (option & OPT_L && option & OPT_P && process->pid == process->pgid)
		return (ft_printf("%d %s %s\n", process->pid, process->running ? RUN : STOP, process->command));
	if (option & OPT_P && process->pid == process->pgid)
		return (ft_printf("%s %s\n", process->running ? RUN : STOP, process->command));
	if (option & OPT_L)
		return (ft_printf("%d %s %s\n", process->pid, process->running ? RUN : STOP, process->command));
	return (ft_printf("%s %s\n", process->running ? RUN : STOP, process->command));
}

uint8_t			print_jobs_info(t_jobs *jobs, t_process *process, int option)
{
	while (process)
	{
		if ((option & OPT_R) && process->running)
			print_process(jobs, process, option);
		else if ((option & OPT_S) && process->running == false)
			print_process(jobs, process, option);
		else if (!(option & OPT_R) && !(option & OPT_S))
			print_process(jobs, process, option);
		process = process->next;
	}
	return (0);
}

void			print_status(t_jobs *jobs, t_process *process)
{
	cursor_column(1);
	(void)jobs;
	(void)process;
	ft_printf("[%d]%c", jobs->index, (jobs->next_use == NULL && process->pid == process->pgid) ? '+' : '\0');
	while (process)
	{
		if (process->status != -1)
		{
			ft_putchar('\t');
			if (WIFEXITED(process->status))
				ft_printf("%d %s %s\n", process->pid,
						status_exit(WEXITSTATUS(process->status)), process->command);
			else if (WIFSIGNALED(process->status))
				ft_printf("%d %s %s\n", process->pid,
						status_signal(WTERMSIG(process->status)), process->command);
			else if (WIFCONTINUED(process->status))
				ft_printf("%d %s %s\n", process->pid,
						status_signal(18), process->command);
			else if (WIFSTOPPED(process->status))
				ft_printf("%d %s %s\n", process->pid,
						status_signal(WSTOPSIG(process->status)), process->command);
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
