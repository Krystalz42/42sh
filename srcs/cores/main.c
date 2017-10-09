/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 18:25:44 by aroulin           #+#    #+#             */
/*   Updated: 2017/09/29 16:44:27 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

void test_cmd();

int			main(void)
{
	init_env();
	logger_init(7, "log");
	jobs_control(INITIALIZE_TO_ZERO, (t_jobs){0, 0, 0, 0, 0, 0}, 0);
	init_term();
	write_history_in_sh();
	var_return(0);
	init_signal();
	test_cmd();
//	shell();
	b_write_history_in_file(get_str_from_history());
	logger_close();
	return (0);
}

void my_execute(char **command, bool foreground)
{
	pid_t child;

	child = fork();

	if (child == -1)
		;
	else if (child)
	{
		(void)foreground;
//		my_wait(child, foreground, true);
	}
	else
	{
		my_execve(command, NULL);
	}
}

/*
setpgid(child,child);
t_jobs child_jobs = (t_jobs){child, getpgid(child), 0, foreground, true, true};
waitpid(child, &child_jobs.status, WNOHANG);
jobs_control(NEW_CHILD, child_jobs, 0);


setpgid(child1, child);
t_jobs child1_jobs = (t_jobs){child1, getpgid(child1), 0, foreground, false, true};
waitpid(child, &child1_jobs.status, WNOHANG);
jobs_control(NEW_CHILD, child1_jobs, 0);
*/

void my_execute_pipe(char **command, char **command1, bool foreground)
{
	pid_t	child;
	pid_t	child1;
	int		fildes[2];

	(void)foreground;
	pipe(fildes);
	child = fork();
	if (child == -1)
		;
	else if (child) // Pere
	{
//		setpgid(child,child);
		t_jobs child_jobs = (t_jobs){child, getpgid(child), 0, foreground, true,true};
		jobs_control(NEW_CHILD, child_jobs, 0);
		child1 = fork();
		if (child1 == -1)
			perror("");
		else if (child1)
		{
//			t_jobs child1_job = (t_jobs){child1, getpgid(child1), 0, foreground, true,true};
//			setpgid(child1, child);
//			jobs_control(NEW_CHILD, child1_job, 0);
//			my_wait(child_jobs);
//			jobs_control(UPDATE_CHILD, child_jobs,0);
			waitpid(-1, NULL, WUNTRACED);
		}
		else
		{
//			setpgid(0,child);
			close(fildes[1]);
			dup2(fildes[0], STDIN_FILENO);
			close(fildes[0]);
			my_execve(command1, NULL);
		}
	}
	else
	{
//		setpgid(0,0);
		close(fildes[0]);
		dup2(fildes[1], STDOUT_FILENO);
		close(fildes[1]);
		my_execve(command, NULL);

	}
}

void test_cmd()
{
	char *lsl[] = {"/bin/ls", "-lR", "/", NULL};
	char *ls[] = {"/bin/ls", "-l", NULL};
	char *cat[] = {"/bin/cat", "-e", NULL};

	(void)ls;
	(void)cat;
	(void)lsl;
	int i = 1;
	log_success("Mon PID [%d] && MOn PPID [%d]", getpid(), getpgid(getpid()));
	while (i)
	{
		read_stdin();
		my_execute_pipe(lsl, cat, true);
		read_stdin();
		jobs_control(FOREGROUND, (t_jobs){-1,0,0,0,0,0},0);
	}
}