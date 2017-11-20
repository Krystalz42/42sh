/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_great_and.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 16:10:18 by jle-quel          #+#    #+#             */
/*   Updated: 2017/11/20 23:36:40 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

/*
*************** TOOLS **********************************************************
*/

static int		get_fildes(char *str)
{
	int			fildes;

	if (!ft_strcmp(str, "-"))
		fildes = open(PATH_ERROR, O_WRONLY);
	else if (ft_strisdigit(str))
	{
		if ((fildes = ft_atoi(str)) > 2)
		{
			ft_dprintf(2, "42sh: %d: Bad file descriptor\n", fildes);
			exit(var_return(1));
		}
	}
	else
		fildes = open(str, OPTION_GREAT, 0644);
	return (fildes);
}

/*
*************** PRIVATE ********************************************************
*/

static void		jobs_op_great_and(t_node *node)
{
	int			std;
	int			fildes;

	std = STDOUT_FILENO;
	if (ft_isdigit(node->content->command[0][0]))
		std = ft_atoi(node->content->command[0]);
	fildes = get_fildes(node->right->content->command[0]);
	if (fildes == -1)
		check_path(node->right->content->command[0]);
	else
	{
		fildes = check_fd(fildes);
		dup2(fildes, std);
	}
}

/*
*************** PUBLIC *********************************************************
*/

uint8_t			op_great_and(t_node *node, t_jobs *jobs, int info)
{
	t_process	*process;

	if (info & FORK)
	{
		if ((jobs = new_jobs(jobs)) == NULL)
			return (var_return(255));
		process = my_fork(jobs, find_executing_node(node), info);
		if (process->pid)
			my_wait(jobs);
		else
		{
			process->pid = getpid();
			if (process->prev)
				write_pipe(process->prev->fildes);
			jobs_op_great_and(node);
			execute_node(node->left, jobs, (info ^ FORK) ^ WRITE_PREVIOUS);
		}
	}
	else
	{
		jobs_op_great_and(node);
		execute_node(node->left, jobs, info);
	}
	return (var_return(-1));
}
