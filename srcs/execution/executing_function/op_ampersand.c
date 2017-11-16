//
// Created by Alexandre ROULIN on 11/1/17.
//

#include <sh.h>

uint8_t			op_ampersand(t_node *node, t_jobs *jobs, int info)
{
	return (execute_node(node->left, jobs, (info ^ FOREGROUND) | FORCE_FORK) +
			execute_node(node->right, jobs, info));
}