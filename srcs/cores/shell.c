/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <aroulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 15:11:34 by aroulin           #+#    #+#             */
/*   Updated: 2017/11/20 18:23:57 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

uint8_t				exec_or_builtin2(t_node *node, int info)
{
	if (check_if_builtin(node, info) == -1)
		my_execve(node->content->command, get_real_env(node));
	else
		exit(var_return(-1));
	return (var_return(-1));
}

t_jobs **new_jobs2(t_jobs **jobs)
{
	t_jobs **addr_jobs;
	t_jobs *temp_jobs;

	addr_jobs = NULL;
	if (jobs == NULL)
	{
		*addr_jobs = jobs_table();
		if (*addr_jobs)
		{
			temp_jobs = *addr_jobs;
			while (temp_jobs && temp_jobs->next)
			{
				dprintf(fd_log, "----KIKOU--\n");
				temp_jobs = temp_jobs->next;
			}
			temp_jobs->next = (t_jobs *)ft_memalloc(sizeof(t_jobs));
			return (&temp_jobs->next);
		}
		else
		{
			*addr_jobs = (t_jobs *)ft_memalloc(sizeof(t_jobs));
			return (addr_jobs);
		}
	}
	return (jobs);
}


t_process		*my_fork2(t_jobs **jobs)
{
	(*jobs)->process = (t_process *)ft_memalloc(sizeof(t_process));
	(*jobs)->process->pid = fork();
	(*jobs)->process->running = true;
	setpgid((*jobs)->process->pid, (*jobs)->process->prev ? (*jobs)->process->prev->pgid : (*jobs)->process->pid);
	(*jobs)->process->pgid = getpgid((*jobs)->process->pid);
	return ((*jobs)->process);
}

uint8_t				jobs_execution2(t_node *node, t_jobs **jobs, int info)
{
	t_process		*process;

	ft_dprintf(fd_log, "VALUE OP_EXECUTION [%d]\n", info);
	jobs = new_jobs2(jobs);
	process = my_fork2(jobs);
	if (process->pid > 0)
	{
	}
	else if (process->pid == 0)
	{
		process->pid = getpid();
		exec_or_builtin2(node, info);
	}
	return (var_return(-1));
}

uint8_t				op_execution2(t_node *node, t_jobs **jobs, int info)
{
	if (info & FORCE_FORK || !(info & FORK))
		jobs_execution2(node, jobs, info);
	else if (check_if_builtin(node, info) != -1)
		;
	else
		jobs_execution2(node, jobs, info);
	return (var_return(-1));
}


int		shell(void)
{
	t_cmd		*input;
	t_parsing	*parse_struct;
	t_node		*tree;

	input = NULL;
	tree = NULL;
	while (0x2A)
	{
		memdel_cmd(&input);
		memdel_node(&tree);
		dprintf(fd_log, "----------------------------------------------------\n");
		dprintf(fd_log, "--------------- New command from [%s]---------------\n", __FILENAME__);
		dprintf(fd_log, "----------------------------------------------------\n");
		if ((input = read_stdin(DEFAULT)) == NULL)
			continue ;
		if ((parse_struct = parsing(input)) == NULL)
			continue ;
		if (!(tree = create_binary_tree(parse_struct, NULL, PRIO_SEPARATOR)))
			continue ;
		check_tree_path(tree);
		if (signal_reception(-1) == SIGINT)
			continue ;
		signal(SIGCHLD, SIG_DFL);
//		execute_node(tree, NULL, FORK | FOREGROUND);
		op_execution2(tree, NULL, 0);
		handler_sigchld(0);
		signal(SIGCHLD, &handler_sigchld);
		cursor_column(1);
	}
	return (0);
}
