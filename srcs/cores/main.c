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
//	test_cmd();
	shell();
	b_write_history_in_file(get_str_from_history());
	logger_close();
	return (0);
}

t_process			*my_fork(t_process *process, pid_t parent, bool foreground, char *command)
{
	process->pid = fork();
	process->running = true;
	process->status = -1;
	process->foreground = foreground;
	process->command = ft_strdup(command);
	log_trace("%s setpgid(%d, %d)", process->pid ? "Daddy" : "Fiston",process->pid, parent ? parent : process->pid);
	setpgid(process->pid, parent ? parent : process->pid);
	process->pgid = getpgid(process->pid);
	return (process);
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
		pjt(*jobs, index);
		my_wait(index);
	}
	else
	{
		my_execve(command, env);
	}
}

//void fg(int i, t_process *process, int fildes[2], bool foreground)
//{
//	t_jobs		*jobs;
//	static int			index;
//	pid_t pgid;
//
//	jobs = jobs_table();
//	pipe(fildes);
//
//	if (process == NULL)
//	{
//		index = get_jobs_index(-1);
//		process = my_fork(jobs[index].process, 0, foreground, 0);
//	}
//	else
//	{
//		pgid = process->pgid;
//		(process) += 1;
//		i++;
//		process = my_fork(process, pgid, foreground, 0);
//	}
//	if (process->pid)
//	{
//		//[READ_PIPE]
//		if (i == 5)
//		{
//			log_warn("Finish PIPELINE [C{1}:C{0}] %d", i);
//			pjt(jobs[index], index);
//		}
//		else
//		{
//			log_warn("Daddy[TEST PIPELINE > %i Execution qui ecrit [C{0}:D{1,1}:C{1}]", i + 1);
//			fg(i, process, fildes, foreground);
//		}
////		execute_ast(ast->left);
//	}
//	else
//	{
//		//execution droite de l'abre qui lis tout le temps
//		//[WRITE_PIPE]
//		//execute_ast(ast->right);
//		log_warn("Child[TEST PIPELINE > %i Execution qui lis [C{1}:D{0,0}:C{0}]", i);
//		exit(EXIT_SUCCESS);
//	}
//}

void my_execute_pipe(char **command, char **command1, bool foreground)
{
	t_jobs		*jobs;
	int			index;
	int		fildes[2];

	jobs = jobs_table();
	index = get_jobs_index(-1);
	pipe(fildes);
	my_fork(jobs[index].process,0, foreground, *command1);
	if (jobs[index].process[0].pid) //father
	{
		my_fork(jobs[index].process + 1, jobs[index].process[0].pid, foreground, *command);
		if (jobs[index].process[1].pid) //father
		{
			close(fildes[0]);
 			close(fildes[1]);
			pjt(*jobs, index);
			my_wait(index);
		}
		else //child2 ls
		{
			close(fildes[0]);
			dup2(fildes[1], STDOUT_FILENO);
			close(fildes[1]);
			my_execve(command, NULL);

		}
	}
	else //child1 cat
	{
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
	char *kill[] = {"kill", "-9", "516156", NULL};
	char *env[] = {"env", "_=", "PATH=pof", "pa= da", "ls", "-l", NULL};

	(void)wc;
	(void)kill;
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
		builtin_env(env, env_table(NULL, ENV_REC));
		read_stdin(DEFAULT);
//		my_execute_pipe(lsl, cat, true); // ls -lR | cat -e
//		read_stdin(DEFAULT);
//		builtin_jobs((char *[]){"jobs", "-ls", NULL},NULL); // jobs -ls
//		read_stdin(DEFAULT);
//		builtin_foreground((char *[]){"fg", NULL}, NULL); // fg
//		read_stdin(DEFAULT);
//		my_execute(cat, NULL, false); // cat -e &
//		read_stdin(DEFAULT);
//		builtin_foreground((char *[]){"fg", NULL}, NULL); // fg
//		read_stdin(DEFAULT);
//		builtin_jobs((char *[]){"jobs", "-l", NULL},NULL);
//		builtin_jobs((char *[]){"jobs", "-lr", NULL},NULL);
//		read_stdin(DEFAULT);
//		builtin_jobs((char *[]){"jobs", "-ps", NULL},NULL);
//		read_stdin(DEFAULT);
//		builtin_jobs((char *[]){"jobs", "-lsr", NULL},NULL);
//		read_stdin(DEFAULT);
//		my_execute(lsl, NULL, false); // ls -lR / &
//		read_stdin(DEFAULT);
//		read_stdin(DEFAULT);
//		builtin_background((char *[]){"bg", NULL}, NULL); // bg
//		my_execute_pipe(cat , ls, false); // ls -l | cat -e &
//		my_execute(cat, NULL, false); // cat &
//		fg(0, NULL, fildes, true);
//		read_stdin(DEFAULT);
//		my_execute(ls_, NULL, false); // ls &
//		read_stdin(DEFAULT);
//		my_execute(ls_, NULL, true); // ls
//		read_stdin(DEFAULT);
//		read_stdin(DEFAULT);
//		read_stdin(DEFAULT);
//		read_stdin(DEFAULT);
//
		}
}
