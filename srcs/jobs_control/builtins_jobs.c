/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_jobs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 18:35:10 by aroulin           #+#    #+#             */
/*   Updated: 2017/10/11 18:35:12 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

void			print_jobs(t_jobs *jobs)
{
	int		index;
	int		index_child;

	index = 0;
	ft_printf("%8s %20s %14s %10s %10s\n", "jobs_spec", "command",
			"status", "PID", "PGID");
	while (index < MAX_CHILD)
	{
		if (jobs[index].father.pid)
		{
			index_child = 0;
			ft_printf("%9d %20s %14s %10d %10d\n", index + 1,
	jobs[index].father.command, jobs[index].father.running ? "running" :
	"suspended", jobs[index].father.pid, jobs[index].father.pgid);
			while (index < MAX_CHILD && jobs[index].child[index_child].pid)
			{
				ft_printf("%s %20s %14s %10d %10d\n", "         ",
	jobs[index].child[index_child].command, jobs[index].father.running
	? "running" : "suspended", jobs[index].child[index_child].pid,
						jobs[index].child[index_child].pgid);
				index_child++;
			}
		}
		index++;
	}
}

void			put_in_foreground(t_jobs *jobs, t_jobs jobs_id)
{
	int index;

	log_error("In Foreground [%d]", jobs_id.father.pid);
	index = MAX_CHILD;
	if (jobs_id.father.pid != -1)
		index = jobs_id.father.pid;
	else
		while (index >= 0 && !(jobs[index].father.pid &&
				!jobs[index].father.foreground))
			index--;
	if (index != -1)
	{
		jobs[index].father.foreground = true;
		if (jobs[index].father.running == false)
			kill(-jobs[index].father.pgid, SIGCONT);
		jobs[index].father.running = true;
		full_update(jobs);
		waitpid(jobs[index].father.pid, &(jobs[index].father.status),
				WUNTRACED);
		jobs_control(UPDATE_CHILD, jobs[index], 0);
	}
	else if (var_return(1))
		STR_FD("job's control : no current job\n", STDERR_FILENO);
}

void			put_in_background(t_jobs *jobs, t_jobs jobs_id)
{
	int index;

	log_error("In background");
	index = MAX_CHILD;
	if (jobs_id.father.pid != -1)
		index = jobs_id.father.pid;
	else
		while (index >= 0 && !((jobs[index].father.pid &&
				!jobs[index].father.running && !jobs[index].father.foreground)))
			index--;
	if (index != -1 && jobs[index].father.pid)
	{
		jobs[index].father.foreground = false;
		if (jobs[index].father.running == false)
			kill(-jobs[index].father.pgid, SIGCONT);
		jobs[index].father.running = true;
		full_update(jobs);
		waitpid(jobs[index].father.pid, &(jobs[index].father.status),
			WUNTRACED | WCONTINUED | WNOHANG);
		jobs_control(UPDATE_CHILD, jobs[index], 0);
	}
	else if (var_return(1))
		STR_FD("Job's control : no current job\n", STDERR_FILENO);
}