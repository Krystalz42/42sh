/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 18:25:44 by aroulin           #+#    #+#             */
/*   Updated: 2017/10/13 14:56:50 by jle-quel         ###   ########.fr       */
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
	log_trace("Return tcgetpgrp (%d)", tcgetpgrp(STDIN_FILENO));
	log_trace("Return tcsetpgrp (%d)", tcsetpgrp(STDIN_FILENO, getpgid(0)));
//	test_cmd();
	shell();
	b_write_history_in_file(get_str_from_history());
	logger_close();
	return (0);
}

int			my_fork(t_process *process, pid_t parent, bool foreground, char *command)
{
	process->pid = fork();
	process->running = true;
	process->foreground = foreground;
	process->command = ft_strdup(command);
	log_debug("%s setpgid(%d, %d)", process->pid ? "Daddy" : "Fiston",process->pid, parent ? parent : process->pid);
	setpgid(process->pid, parent ? parent : process->pid);
	process->pgid = getpgid(process->pid);
	return 0;
}


void my_execute(char **command, char **env, bool foreground)
{
	t_jobs		*jobs;
	int			index;

	jobs = jobs_table();
	index = get_jobs_index(-1);
	my_fork(jobs[index].process, 0, foreground, *command);
	if (jobs[index].process->pid == -1)
		;
	else if (jobs[index].process->pid)
	{
		my_wait(index);

	}
	else
	{
		my_execve(command, env);
	}
}

void my_execute_pipe(char **command, char **command1, bool foreground)
{
	t_jobs		*jobs;
	int			index;
	int		fildes[2];

	jobs = jobs_table();
	index = get_jobs_index(-1);



	pipe(fildes);
	my_fork(jobs[index].process + 0, 0, foreground, *command1);
	if (jobs[index].process[0].pid)
	{
		close(fildes[0]);
		close(fildes[1]);
		my_fork(jobs[index].process + 1, jobs[index].process[0].pid, foreground, *command);
		if (jobs[index].process[1].pid)
		{

			pjt(*jobs, index);
			my_wait(index);
		}
		else
		{
			dup2(fildes[1], STDOUT_FILENO);
			my_execve(command, NULL);
		}
	}
	else
	{
		jobs[index].process[0].pid = getpid();
		close(fildes[1]);
		dup2(fildes[0], STDIN_FILENO);
		close(fildes[0]);
		my_execve(command1, NULL);
	}
}

void test_cmd()
{
	char *lsl[] = {"/bin/ls", "-lR", "/", NULL};
	char *wc[] = {"/usr/bin/wc", NULL};
	char *ls[] = {"/bin/ls", "-l", NULL};
	char *ls_[] = {"/bin/ls", NULL};
	char *cat[] = {"/bin/cat", "-e", NULL};
	char *vim[] = {"/usr/bin/vim", NULL};
	char *emacs[] = {"/usr/bin/emacs", NULL};
	char *jobs[] = {"jobs", NULL};
	char *jobsR[] = {"jobs", "-r", NULL};
	char *jobsP[] = {"jobs", "-p", NULL};
	char *jobsS[] = {"jobs", "-s", NULL};
	char *my_shell[] = {"./42sh", NULL};

	(void)wc;
	(void)jobs;
	(void)my_shell;
	(void)jobsR;
	(void)jobsS;
	(void)jobsP;
	(void)ls;
	(void)ls_;
	(void)vim;
	(void)emacs;
	(void)cat;
	(void)lsl;
	int i = 1;
	log_success("Mon PID [%d] && Mon PPID [%d] && Mon PGID [%d]", getpid(), getppid(), getpgid(getpid()));
	while (i)
	{
		read_stdin(DEFAULT);
		my_execute_pipe(ls , cat, false); // ls -l | cat -e &
		read_stdin(DEFAULT);
//		my_execute(ls_, NULL, false); // ls &
//		read_stdin(DEFAULT);
//		my_execute(ls_, NULL, true); // ls
//		read_stdin(DEFAULT);
//		my_execute(cat, NULL, false); // cat &
//		read_stdin(DEFAULT);
//		my_execute(cat, NULL, true); // cat -e
		read_stdin(DEFAULT);
		}
}
