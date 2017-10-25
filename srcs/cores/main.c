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
	test_cmd();
//	shell();
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
//	int			index;
//
//	pipe(fildes);
//	jobs = jobs_table();
//	index = get_jobs_index(-1);
//	if (i == 2)
//		return ;
//	if (process == NULL)
//	{
//		process = my_fork(jobs[index].process, 0, foreground, 0);
//	}
//	else
//	{
//		(process) += 1;
//		process = my_fork(process, process->pgid, foreground, 0);
//	}
//	if (process->pid)
//	{
//		//[READ_PIPE]
//		fg(i + 1, process + 1, fildes, foreground);
////		execute_ast(ast->right);
//	}
//	else
//	{
//		//[WRITE_PIPE]
//		log_warn("[TEST PIPELINE > %i ]", i);
//		exit(EXIT_SUCCESS);
//		//execute_ast(ast->left);
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
	my_fork(jobs[index].process,0, foreground, *command);
	if (jobs[index].process[0].pid) //father
	{
		my_fork(jobs[index].process + 1, jobs[index].process[0].pid, foreground, *command1);
		if (jobs[index].process[1].pid) //father
		{
			close(fildes[0]);
 			close(fildes[1]);
			pjt(*jobs, index);
			my_wait(index);
		}
		else //child2 ls
		{
			close(fildes[1]);
			dup2(fildes[0], STDIN_FILENO);
			close(fildes[0]);
			my_execve(command1, NULL);
		}
	}
	else //child1 cat
	{
		close(fildes[0]);
		dup2(fildes[1], STDOUT_FILENO);
		close(fildes[1]);
		my_execve(command, NULL);

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
		my_execute_pipe(ls, cat, true);
		read_stdin(DEFAULT);
//		my_execute(cat, NULL, false); // cat &
//		read_stdin(DEFAULT);
//		read_stdin(DEFAULT);
//		builtin_jobs((char *[]){"jobs", "-s", NULL},NULL);
//		read_stdin(DEFAULT);
//		builtin_jobs((char *[]){"jobs", "-l", NULL},NULL);
//		read_stdin(DEFAULT);
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
//		read_stdin(DEFAULT);
//		my_execute(ls_, NULL, false); // ls &
//		read_stdin(DEFAULT);
//		my_execute(ls_, NULL, true); // ls
//		read_stdin(DEFAULT);
//		read_stdin(DEFAULT);
//		builtin_foreground((char *[]){"fg", NULL}, NULL); // fg
//		read_stdin(DEFAULT);
//		my_execute(cat, NULL, true); // cat -e
		read_stdin(DEFAULT);

		}
}
