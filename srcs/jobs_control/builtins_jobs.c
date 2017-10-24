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

/*
**		[0]		List all process.
**	-p	[1]		List only the process ID of the job’s process group leader.
**	-r	[2]		Display only running jobs.
**	-s	[4]		Display only stopped jobs.
*/

//static uint8_t		error_jobs(void)
//{
//	ft_putstr_fd("jobs: no current jobs\n", STDERR_FILENO);
//	return (1);
//}
//
//static void			print_evrything(t_jobs jobs, int option)
//{
//	int		index;
//
//	index = 0;
//	if (!(option % 2))
//		while (index < MAX_CHILD && jobs.child[index].pid)
//		{
//			ft_printf("          %20s %14s %10d %10d\n",
//		jobs.child[index].command, jobs.father.running
//		? "running" : "suspended", jobs.child[index].pid,
//		jobs.child[index].pgid);
//		index++;
//		}
//}
//
//uint8_t			print_jobs(t_jobs *jobs, int option)
//{
//	int		index;
//	int		print;
//
//
//	index = 0;
//	print = 0;
//	while (index < MAX_CHILD)
//	{
//		if (jobs[index].father.pid && (!option  || option % 2 || (!(option % 2)
//				&& jobs[index].father.running) || (!(option % 4)
//								&& !jobs[index].father.running)))
//		{
//			if (!print++)
//				ft_printf("%8s %20s %14s %10s %10s\n", "jobs_spec", "command",
//						  "status", "PID", "PGID");
//			ft_printf("%9d %20s %14s %10d %10d\n", index + 1,
//		jobs[index].father.command, jobs[index].father.running ? "running" :
//		"suspended", jobs[index].father.pid, jobs[index].father.pgid);
//					 print_evrything(jobs[index], option);
//		}
//	index++;
//	}
//	return ((uint8_t)(print ? 0 : error_jobs()));
//}
//
//void			put_in_foreground(t_jobs *jobs, pid_t jobs_id)
//{
//	int index;
//
//	log_error("In Foreground [%d]", jobs_id);
//	index = MAX_CHILD;
//	if (jobs_id != -1)
//		index = jobs_id;
//	else
//		while (index >= 0 && !(jobs[index].father.pid &&
//				!jobs[index].father.foreground))
//			index--;
//	if (index != -1)
//	{
//		modify_foreground(&(jobs[index]), true);
//		if (jobs[index].father.running == false)
//			kill(-jobs[index].father.pgid, SIGCONT);
//		modify_runing(&(jobs[index]), true);
//		jobs_control(UPDATE_CHILD, jobs[index], WUNTRACED | WCONTINUED);
//	}
//	else if (var_return(1))
//		STR_FD("fg: no current job\n", STDERR_FILENO);
//}
//
//void			put_in_background(t_jobs *jobs, pid_t jobs_id)
//{
//	int index;
//
//	log_error("In background");
//	index = MAX_CHILD;
//	if (jobs_id != -1)
//		index = jobs_id;
//	else
//		while (index >= 0 && !(jobs[index].father.pid &&
//				!jobs[index].father.running && !jobs[index].father.foreground))
//			index--;
//	if (index != -1 && jobs[index].father.pid && !var_return(0))
//	{
//		modify_foreground(&(jobs[index]), false);
//		modify_runing(&(jobs[index]), true);
//		jobs_control(UPDATE_CHILD, jobs[index], WUNTRACED | WCONTINUED | WNOHANG);
//	}
//	else if (var_return(1))
//		STR_FD("bg: no current job\n", STDERR_FILENO);
//}