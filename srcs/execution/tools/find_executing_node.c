//
// Created by Alexandre ROULIN on 11/12/17.
//

#include <sh.h>

t_node			*find_executing_node(t_node *node)
{
	if (node->content->priority == PRIO_PIPE)
		return (find_executing_node(node->right));
	if (node->content->priority == PRIO_REDIR)
		return (find_executing_node(node->left));
	return (node);
}