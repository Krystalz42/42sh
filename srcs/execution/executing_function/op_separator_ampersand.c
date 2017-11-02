//
// Created by Alexandre ROULIN on 11/1/17.
//

#include <sh.h>

uint8_t		op_ampersand(t_node *node, int info)
{
	execute_node(node->left, info - BACKGROUND);
	return (execute_node(node->right, info));
}