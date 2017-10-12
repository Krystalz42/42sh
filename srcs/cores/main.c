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

int			main(int ac, char **av)
{
	(void)ac;
	(void)av;
	init_env();
	logger_init(7, "log");
	init_term();
	write_history_in_sh(get_str_from_history());
	init_signal();
	test_cmd();
//	shell();
	b_write_history_in_file(get_str_from_history());
	logger_close();
	return (0);
}
t_process		init_jobs(pid_t child, pid_t parent_pid, bool foreground, char *command)
{
	t_process		identify;

	setpgid(child, parent_pid);
	identify = (t_process){child, getpgid(child), 0, foreground, true, ft_strdup(command)};
	waitpid(child, &identify.status, WNOHANG);
	return (identify);
}
void my_execute(char **command, bool foreground)
{
	pid_t child;
	t_jobs jobs;

	jobs = new_jobs(0);
	child = fork();
	if (child == -1)
		;
	else if (child)
	{
		jobs.father = init_jobs(child, child, foreground, command[0]);
		my_wait(jobs);
	}
	else
	{
		my_execve(command, NULL);
	}
}

void my_execute_pipe(char **command, char **command1, bool foreground)
{
	pid_t	child;
	pid_t	child1;
	int		fildes[2];
	t_jobs	jobs;

	jobs = new_jobs(0);
	pipe(fildes);
	child = fork();
	if (child == -1)
		;
	else if (child)
	{
		jobs.father = init_jobs(child, child, foreground, *command);
		child1 = fork();
		if (child1 == -1)
			perror("");
		else if (child1)
		{
			jobs.child[0] = init_jobs(child1, child, foreground, *command1);
			my_wait(jobs);
		}
		else
		{
			setpgid(0,child);
			close(fildes[1]);
			dup2(fildes[0], STDIN_FILENO);
			close(fildes[0]);
			my_execve(command1, NULL);
		}
	}
	else
	{
		setpgid(0,0);
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
	char *vim[] = {"/usr/bin/vim", NULL};
	char *emacs[] = {"/usr/bin/emacs", NULL};
	char *jobs[] = {"jobs", NULL};
	char *jobsR[] = {"jobs", "-r", NULL};
	char *jobsP[] = {"jobs", "-p", NULL};
	char *jobsS[] = {"jobs", "-s", NULL};

	(void)jobs;
	(void)jobsR;
	(void)jobsS;
	(void)jobsP;
	(void)ls;
	(void)vim;
	(void)emacs;
	(void)cat;
	(void)lsl;
	int i = 1;
	log_success("Mon PID [%d] && MOn PPID [%d]", getpid(), getpgid(getpid()));
	while (i)
	{
		read_stdin();
		my_execute(ls, true);
		read_stdin();
		builtin_jobs(jobs, NULL);
		read_stdin();
	}
}