
#include <sh.h>

uint8_t			execute_node(t_node *node, t_jobs *jobs, int info)
{
	static t_exec		*execute[11] = {
		[VALUE_COMMAND] = &op_execution,
		[VALUE_SEMI_COLON] = &op_separator,
		[VALUE_AMPERSAND] = &op_ampersand,
		[VALUE_AND_IF] = &op_and_if,
		[VALUE_PIPELINE] = &op_pipeline,
		[VALUE_DLESS] = &op_dless,
		[VALUE_LESS] = &op_less,
		[VALUE_GREAT] = &op_great,
		[VALUE_DGREAT] = &op_dgreat,
		[VALUE_OR_IF] = &op_or_if,
		[VALUE_GREAT_AND] = &op_great_and,
	};
	if (node)
		execute[node->content->value](node, jobs, info);
	return (0);
}