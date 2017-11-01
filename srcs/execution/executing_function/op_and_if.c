//
// Created by Alexandre ROULIN on 11/1/17.
//

#include <sh.h>

uint8_t			op_and_if(t_node *node, int info)
{
	uint8_t			ret;

	if ((ret = execute_node(node->left, info)) == 0)
		return (execute_node(node->right, info));
	return (ret);
}