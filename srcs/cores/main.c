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

void execute(char **command, bool foreground)
{
	pid_t child;

	child = fork();

	if (child == -1)
		;
	else if (child)
	{
		my_wait(child, foreground);
	}
	else
	{
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
	log_success("Mon PID [%d] && MOn PPID [%d]", getpid(), getpgid(getpid()));
	read_stdin();
	execute(lsl, true);
	read_stdin();
	execute(lsl, true);
	read_stdin();
	jobs_control(FOREGROUND, (t_jobs){-1, 0, 0, 0, 0, 0}, 0);
	read_stdin();
}