//
// Created by Alexandre ROULIN on 11/1/17.
//

#include <sh.h>

char			**get_real_env(t_node *node)
{
	if (node->content->env_option)
		return (node->content->env);
	else
		return (env_table(NULL, ENV_REC));
}