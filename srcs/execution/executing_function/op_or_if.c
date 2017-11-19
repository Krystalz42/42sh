/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_or_if.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 16:17:58 by jle-quel          #+#    #+#             */
/*   Updated: 2017/11/19 04:05:31 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

/*
*************** PUBLIC *********************************************************
*/

uint8_t			op_or_if(t_node *node, t_jobs *jobs, int info)
{
	execute_node(node->left, jobs, info);
	var_return(-1) ? execute_node(node->right, jobs, info) : 0;
	return (var_return(-1));
}
