/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_great_and.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 16:10:18 by jle-quel          #+#    #+#             */
/*   Updated: 2017/11/18 22:06:56 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

/*static int		check_fd(int fildes)
  {
  if (fildes == init_fd())
  fildes = STDOUT_FILENO;
  return (fildes);
  }

  static void		jobs_op_great_and(t_node *node)
  {
  int			fildes;

  if (node->right->content->command[0][0] == '-')
  fildes = open(PATH_ERROR, O_WRONLY);
  else if (ft_strisdigit(node->right->content->command[0]))
  fildes = ft_atoi(node->right->content->command[0]);
  else
  {
  fildes = open(node->right->content->command[0], OPTION_GREAT, 0644);
  fildes == -1 ? check_path(node->right->content->command[0]) : 0;
  }
  fildes = check_fd(fildes);
  if (ft_isdigit(node->content->command[0][0]))
  dup2(fildes, ft_atoi(node->content->command[0]));
  else
  dup2(fildes, STDOUT_FILENO);
  close(fildes);
  }

  uint8_t			op_great_and(t_node *node, t_jobs *jobs, int info)
  {
  log_debug("VALUE GREAT_AND %d", info);
  if (info & FORK)
  {
  if ((jobs = new_jobs(jobs)) == NULL)
  return (var_return(255));
  jobs->process = my_fork(jobs, find_executing_node(node), info);
  if (jobs->process->pid)
  {
  my_wait(jobs);
  }
  else
  {
  jobs->process->pid = getpid();
  jobs_op_great_and(node);
  execute_node(node->left, jobs, (info ^ FORK));
  }
  }
  else
  {
  jobs_op_great_and(node);
  execute_node(node->left, jobs, info);
  }
  return (var_return(-1));
  }*/

/*
 * *************** TOOLS **********************************************************
 * */

static int		check_fd(int fildes)
{
	if (fildes == init_fd())
		fildes = STDOUT_FILENO;
	return (fildes);
}

static int		get_fildes(char *str)
{
	int			fildes;

	if (!ft_strcmp(str, "-"))
		fildes = open(PATH_ERROR, O_WRONLY);
	else if (ft_strisdigit(str))
		fildes = ft_atoi(str);
	else
		fildes = open(str, OPTION_GREAT, 0644);
	return (fildes);
}

/*
 * *************** PRIVATE ********************************************************
 * */

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
		dup2(fildes, std ? std : STDOUT_FILENO);
	}
}

/*
 * *************** PUBLIC *********************************************************
 * */

uint8_t			op_great_and(t_node *node, t_jobs *jobs, int info)
{
	t_process			*process;

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
			jobs_op_great_and(node);
			execute_node(node->left, jobs, (info ^ FORK));
		}
	}
	else
	{
		jobs_op_great_and(node);
		execute_node(node->left, jobs, info);
	}
	return (var_return(-1));
}
