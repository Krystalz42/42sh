/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executing_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 16:09:00 by jle-quel          #+#    #+#             */
/*   Updated: 2017/12/14 13:42:42 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

t_exec			*g_execute[12] =
{
	[VALUE_COMMAND] = &op_execution,
	[VALUE_SEMI_COLON] = &op_separator,
	[VALUE_AMPERSAND] = &op_ampersand,
	[VALUE_AND_IF] = &op_and_if,
	[VALUE_PIPELINE] = &op_pipeline,
	[VALUE_OR_IF] = &op_or_if,
};

uint8_t			execute_node(t_node *node, t_jobs *jobs, int info)
{
	ft_putnbr(node->content->value);
	if (node)
		g_execute[node->content->value](node, jobs, info);
	return (var_return(-1));
}
