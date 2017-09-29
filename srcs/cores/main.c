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

void info(char *str)
{
	dprintf(fdb, "[%s] pid:%d pgid:%d\n", str,(int)getpid(), (int)getpgid(0));
}

void fg(char *mkdir[])
{

	pid_t father = fork();

	if (father)
	{
		wait(NULL);
	}
	else
	{
		info(mkdir[0]);
		if ((setpgid(0, 0)) == -1)
			perror("setpgit");
		execve(mkdir[0], mkdir, NULL);
	}
}

void bg(char *mkdir[])
{
	pid_t father = fork();

	if (father)
		;
	else
	{
		if ((setpgid(0, 0)) == -1)
			perror("setpgit");
		info(mkdir[0]);
		execve(mkdir[0], mkdir, NULL);
	}
}

void bgfd(char *mkdir[], int fd)
{
	pid_t father = fork();
	(void)fd;
	if (father)
		;
	else
	{
		setpgid(0, 0);
		dup2(fd, 1);
		dup2(fd, 2);
		info(mkdir[0]);
		execve(mkdir[0], mkdir, NULL);
	}
}

void test(void)
{
	char *mkdir[] = {"/bin/mkdir", "salut", NULL};
	char *lsl[] = {"/bin/ls", "-lR","/", NULL};
	char *echo[] = {"/bin/echo", "Salut =D", NULL};
	int fd = open("./ls", O_CREAT | O_TRUNC | O_WRONLY, 0644);
	char *ls[] = {"/bin/ls", "-l", NULL};


	info("MAIN TEST");
	remove("./salut");
	bgfd(lsl, fd);
	read_stdin();
	bg(ls);
	fg(echo);
	fg(mkdir);
	fg(echo);
	fg(ls);
	fg(echo);
}

int		main(void)
{

	init_env();
	fdb = open("./logger", O_CREAT | O_TRUNC | O_WRONLY, 0644);
	write_history_in_sh();
	init_hash();
	if (init_term())
		return (1);
	var_return(1);
	create_table_env();
	test();
	shell();
	b_write_history_in_file(get_str_from_history());
	return (0);
}
