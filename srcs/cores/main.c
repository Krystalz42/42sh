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


void test(void)
{
//	char *mkdir[] = {"/bin/mkdir", "salut", NULL};
	char *lsl[] = {"/bin/ls", "-lR","/", NULL};
//	char *ls[] = {"/bin/ls", "-l", NULL};
//	char *echo[] = {"/bin/echo", "Salut =D", NULL};
    char *cat[] = {"/bin/cat", "-e", NULL};
//    char *wc[] = {"/usr/bin/wc", NULL};
//	int fd = open("./ls", O_CREAT | O_TRUNC | O_WRONLY, 0644);
	pid_t father;
    pid_t father1;
    pid_t father2;
    pid_t father3;
    int fildes[2];

    info("MAIN TEST");

	father = fork();
	if (father)
	{
        STR_FD("Father ==", fdb); NBR_FD(father, fdb); CHAR_FD(10,fdb);
        sleep(5);
        kill(father, 9);

    }
	else
	{
        setpgid(0, getpid());
        pipe(fildes);
        father1 = fork();
        if (father1)
		{

            STR_FD("Father1 ==", fdb); NBR_FD(father1, fdb); CHAR_FD(10,fdb);


            close(fildes[1]);
            dup2(fildes[0], STDIN_FILENO);
            close(fildes[0]);

            info("cat -e");
            execve(*cat, cat, 0);
        }
		else
		{

            close(fildes[0]);
            dup2(fildes[1], STDOUT_FILENO);
            close(fildes[1]);

            info("ls -lR");
            execve(*lsl, lsl, 0);
        }
	}
	remove("./salut");
}

int			main(void)
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
