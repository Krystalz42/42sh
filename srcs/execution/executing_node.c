//
// Created by Alexandre ROULIN on 10/31/17.
//


#include <sh.h>

t_exec			g_affect_fct[] = {
		(t_exec){VALUE_COMMAND, &simple_execution},
		(t_exec){VALUE_SEMI_COLON, &op_separator},
		(t_exec){VALUE_AMPERSAND, NULL},
		(t_exec){VALUE_AND_IF, NULL},
		(t_exec){VALUE_OR_IF, NULL},
		(t_exec){VALUE_PIPELINE, &op_pipeline},
		(t_exec){VALUE_LESS, NULL},
		(t_exec){VALUE_GREAT, NULL},
		(t_exec){VALUE_DLESS, NULL},
		(t_exec){VALUE_DGREAT, NULL},
		(t_exec){VALUE_LESS_AND, NULL},
		(t_exec){VALUE_GREAT_AND, NULL},
		(t_exec){NOTHING, NULL}
};



uint8_t			execute_node(t_node *tree, int info)
{
	int			index;

	index = 0;
	while (g_affect_fct[index].value != NOTHING)
	{
		if (g_affect_fct[index].value == tree->content->value)
			return (g_affect_fct[index].function(tree, info));
		index++;
	}
	return (0);
}
