//
// Created by Alexandre ROULIN on 11/2/17.
//

#include <sh.h>

//uint8_t			op_less_work(t_node *node, int info, int *fildes)
//{
//	dup2(fildes[1], fildes[0]);
//	close(fildes[1]);
//	execute_node(node->left, info);
//	return (var_return(-1));
//}
//
//uint8_t			op_less(t_node *node, int info)
//{
//	int		fildes[2];
//	t_jobs	*jobs;
//
//	fildes[0] = ft_atoi(node->content->input);
//	if ((fildes[1] = open(node->right->content->command[0], O_RDONLY)) == -1)
//		exit(1);
//	if (info & FORK)
//	{
//		if ((jobs = new_jobs()) == NULL)
//			return (var_return(255));
//		jobs->process = my_fork(jobs, node, info);
//		if (jobs->process->pid > 0)
//			my_wait(jobs);
//		else
//			op_less_work(node, info ^ FORK, fildes);
//	}
//	else
//		op_less_work(node, info, fildes);
//	return (var_return(-1));
//}
