/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executing_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 16:09:00 by jle-quel          #+#    #+#             */
/*   Updated: 2017/11/20 02:00:45 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

t_exec			*g_execute[11] =
{
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

uint8_t			execute_node(t_node *node, t_jobs *jobs, int info)
{
	if (node)
		g_execute[node->content->value](node, jobs, info);
	return (var_return(-1));
}
