/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_less_and.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 13:41:56 by jle-quel          #+#    #+#             */
/*   Updated: 2017/12/14 15:56:42 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

/*
*************** TOOLS **********************************************************
*/

static int		get_fildes(char *str)
{
	int			fildes;
	
	if (ft_isdigit(*str))
		fildes = ft_atoi(str);
	else
	{
		error_msg(S42H, "ambiguous redirect: ", str);
		exit(1);
	}
	return (fildes);
}

static int		get_std(char *str)
{
	int			std;

	if (ft_isdigit(*str))
		std = ft_atoi(str);
	else
		std = STDIN_FILENO;
	return (std);
}

/*
*************** PRIVATE ********************************************************
*/

static void		jobs_op_less_and(t_node *node)
{
	int			fildes;
	int			std;

	fildes = get_fildes(node->right->content->command[0]);
	std = get_std(node->content->command[0]);
	printf("fildes [%d] std [%d]\n", fildes, std);
	dup2(fildes, std);
}

/*
*************** PUBLIC *********************************************************
*/

uint8_t			op_less_and(t_node *node, t_jobs *jobs, int info)
{
	t_process	*process;

	if (info & FORK)
	{
		jobs = new_jobs(jobs);
		if ((process = my_fork(jobs, find_executing_node(node), info)) == NULL)
			return (var_return(255));
		if (process->pid)
			my_wait(jobs);
		else
		{
			process->pid = getpid();
			if (process->prev)
				write_pipe(process->prev->fildes);
			jobs_op_less_and(node);
			execute_node(node->left, jobs, (info ^ FORK) ^ WRITE_PREVIOUS);
		}
	}
	else
	{
		jobs_op_less_and(node);
		execute_node(node->left, jobs, info);
	}
	return (var_return(-1));
}
