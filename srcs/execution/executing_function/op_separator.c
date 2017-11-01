//
// Created by Alexandre ROULIN on 11/1/17.
//

#include <sh.h>

uint8_t				op_separator(t_node *node, int info)
{
	return (execute_node(node->left, info) + execute_node(node->right, info));
}