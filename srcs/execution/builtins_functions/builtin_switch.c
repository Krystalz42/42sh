//
// Created by Alexandre ROULIN on 10/14/17.
//

#include <sh.h>

static uint8_t		error_switch(char *from, char *error)
{
	ft_putstr_fd(from, STDERR_FILENO);
	ft_putstr_fd(error, STDERR_FILENO);
	return (1);
}

uint8_t				fg_switch_process(t_jobs *jobs, int index, char *from)
{
	if (index != -1 && jobs[index].process->pid)
	{
		reset_signal();
		modify_foreground(jobs[index].process, true);
		set_fidles(jobs[index].process->pgid);
		if (!jobs[index].process->running)
		{
			kill(-(jobs[index].process->pgid), SIGCONT);
			modify_runing(jobs[index].process, true);
			update_status(jobs[index].process);
			print_status(jobs[index].process, index);
		}
		wait_process(jobs[index].process, index);
		set_fidles(getpgid(0));
		init_signal();
		return (0);
	}
	else
		return (error_switch("fg:", from));
}

uint8_t				bg_switch_process(t_jobs *jobs, int index, char *from)
{
	if (index != -1 && jobs[index].process->pid)
	{
		modify_runing(jobs[index].process, true);
		modify_foreground(jobs[index].process, false);
		kill(-jobs[index].process->pgid, SIGCONT);
		update_status(jobs[index].process);
		print_status(jobs[index].process, index);
		pjt(jobs[index], index);
		return (0);
	}
	else
		return (error_switch("bg:", from));
}

uint8_t				builtin_foreground(char **command, char **env)
{
	int			id;
	t_jobs		*jobs;

	(void)env;
	jobs = jobs_table();
	if (command[1] && command[1][0] == '%')
	{
		id = ft_atoi(command[1] + 1);
		return (var_return(fg_switch_process(jobs, id, command[1] + 1)));

	}
	else
	{
		id = MAX_CHILD - 1;
		while (jobs[id].process->pid == 0 && jobs[id].process->foreground == false)
			id--;
		return (fg_switch_process(jobs, id, " no current jobs\n"));
	}
}

uint8_t				builtin_background(char **command, char **env)
{
	int			id;
	t_jobs		*jobs;

	(void)env;
	jobs = jobs_table();
	if (command[1] && command[1][0] == '%')
	{
		id = ft_atoi(command[1] + 1);
		return (var_return(bg_switch_process(jobs, id, command[1] + 1)));
	}
	else
	{
		id = MAX_CHILD - 1;
		while (jobs[id].process->pid == 0 && jobs[id].process->running == false)
			id--;
		return (var_return(bg_switch_process(jobs, id, " no current jobs\n")));
	}
}