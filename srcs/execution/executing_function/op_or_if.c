//
// Created by Alexandre ROULIN on 11/1/17.
//

#include <sh.h>

uint8_t			op_or_if(t_node *node, t_jobs *jobs, int info)
{
	uint8_t			ret;

	if ((ret = execute_node(node->left, jobs, info)) > 0)
		return (execute_node(node->right, jobs, info));
	return (ret);
}