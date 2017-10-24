/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jobs_control.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 19:09:46 by aroulin           #+#    #+#             */
/*   Updated: 2017/10/11 19:09:48 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

t_jobs				*jobs_table(void)
{
	static t_jobs		jobs[MAX_CHILD];

	return (jobs);
}

void			update_jobs(t_process *process, int index)
{
	log_warn("/!\\  [PROCESS %d HAS BEEN FINISH] /!\\", index);
	int			index_child;

	index_child = 0;
	while (process[index_child].pid)
	{
		if (WIFEXITED(process[index_child].status))
			var_return(WEXITSTATUS(process[index_child].status));
		else if (WIFSIGNALED(process[index_child].status))
			var_return(WTERMSIG(process[index_child].status) + 128);
		else if (WIFCONTINUED(process[index_child].status))
			;
		else if (WIFSTOPPED(process[index_child].status))
			var_return(WSTOPSIG(process[index_child].status) + 128);
		index_child++;
	}
}

int					get_jobs_index(pid_t search)
{
	t_jobs			*jobs;
	int				index;

	jobs = jobs_table();
	index = MAX_CHILD - 1;
	if (search == -1)
	{
		while (index >= 0 && jobs[index].process->pid == 0)
			index--;
		log_trace("Get new index [%d]", index + 1);
		return (index + 1);
	}
	else
	{
		while (index >= 0 && jobs[index].process->pid != search)
			index--;
		return (index);
	}
}

void			print_status(t_process *process, int jobs_spec)
{
	log_warn("/!\\  [PROCESS %d HAS BEEN MODIFY] /!\\", jobs_spec);
	int			index;

	index = 0;
	while (process[index].pid)
	{
		index ? CHAR('\t') : ft_printf("[%d]\t", jobs_spec + 1);
		if (WIFEXITED(process[index].status))
			ft_printf("%d %s %d %s\n", process[index].pid, WEXITSTATUS(process[index].status) ? "exit" : "done", WEXITSTATUS(process[index].status), process[index].command);
		else if (WIFSIGNALED(process[index].status))
			ft_printf("%d %s %d %s\n", process[index].pid, "killed", WTERMSIG(process[index].status), process[index].command);
		else if (WIFCONTINUED(process[index].status))
			ft_printf("%d %s %s\n", process[index].pid,"continued", process[index].command);
		else if (WIFSTOPPED(process[index].status))
			ft_printf("%d %s %d %s\n", process[index].pid, "suspended", WSTOPSIG(process[index].status), process[index].command);
		index++;
	}
	ioctl(STDIN_FILENO, TIOCSTI, "\16");
}

int				update_status(t_process *process)
{
	int				ret;
	int				index;
	int				status;

	index = 0;
	ret = 0;
	while (process[index].pid)
	{
		if ((waitpid(process[index].pid, &status, WCONTINUED | WNOHANG | WUNTRACED)) > 0)
		{
			ret = 1;
			process[index].status = status;
		}
		index++;
	}
	log_trace("Return update_status %d", ret);
	return (ret);
}

int					terminate_process(t_process *process)
{
	int			index_child;
	int			ret;

	index_child = 0;
	ret = 1;
	while (process[index_child].pid)
	{
		log_trace("In terminated process for %d [%d.%d]",process[index_child].pid, WIFSIGNALED(process[index_child].status), WIFEXITED(process[index_child].status));
		if (!WIFSIGNALED(process[index_child].status) && !WIFEXITED(process[index_child].status))
			ret = 0;
		index_child++;
	}
	log_trace("Return terminated_status %d", ret);
	return (ret);
}

void				handler_sigchld(int sig)
{
	t_jobs			*jobs;
	int				index;

	log_warn("/!\\  [SIGCHLD RECEPTION %d] /!\\", sig);
	index = MAX_CHILD -1;
	jobs = jobs_table();
	while (index >= 0)
	{
		if (jobs[index].process->pid && !jobs[index].process->foreground)
		{
			if (update_status(jobs[index].process))
				print_status(jobs[index].process, index);
			if (terminate_process(jobs[index].process))
			{
				log_warn("/!\\  [PROCESS %%%d TERMINATED] /!\\", index);
				update_jobs(jobs[index].process, index);
				reset_process(jobs[index].process);
			}
			else
			{
				modify_runing(jobs[index].process, false);
				modify_foreground(jobs[index].process, false);
			}
			pjt(jobs[index], index);
		}
		index--;
	}
}
