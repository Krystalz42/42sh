//
// Created by Alexandre ROULIN on 11/1/17.
//

#include <sh.h>

uint8_t				op_separator(t_node *node, t_jobs *jobs, int info)
{
	return (execute_node(node->left, jobs, info) +
			execute_node(node->right, jobs, info));
}