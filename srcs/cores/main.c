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
	logger_init(7, "log");
	init_env();
	jobs_control(INITIALIZE_TO_ZERO, (t_jobs){0, 0, 0, 0, 0, 0}, 0);
	write_history_in_sh();
	init_term();
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
		my_wait(child, foreground, true);
	}
	else
	{
		my_execve(command, NULL);
	}
}

#include <sys/mman.h>

void my_execute_pipe(char **command, char **command1, bool foreground)
{
	pid_t child;
	pid_t child1;
	int 	fildes[2];
	t_jobs	*ptitchild = mmap(NULL, sizeof(t_jobs), PROT_READ | PROT_WRITE,
							MAP_SHARED | MAP_ANONYMOUS, -1, 0);

	child = fork();
	if (child == -1)
		;
	else if (child)
	{
		my_wait(child, foreground, true);
	}
	else
	{
		pipe(fildes);
		child1 = fork();
		if (child1 == -1)
			perror("");
		else if (child1)
		{
			close(fildes[1]);
			dup2(fildes[0], STDIN_FILENO);
			close(fildes[0]);
			my_execve(command1, NULL);
		}
		else
		{
			ptitchild[0] = (t_jobs){getpid(), getpgid(0), 0, foreground, false, true};
			close(fildes[0]);
			dup2(fildes[1], STDOUT_FILENO);
			close(fildes[1]);
			my_execve(command, NULL);
		}
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
		my_execute(ls, true);
		read_stdin();
		my_execute_pipe(lsl, cat, true);
		read_stdin();
		jobs_control(FOREGROUND, (t_jobs){0,0,0,0,0,0},0);

	}
}