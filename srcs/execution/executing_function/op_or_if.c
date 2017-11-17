/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_or_if.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 16:17:58 by jle-quel          #+#    #+#             */
/*   Updated: 2017/11/17 16:18:04 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

uint8_t			op_or_if(t_node *node, t_jobs *jobs, int info)
{
	uint8_t			ret;

	if ((ret = execute_node(node->left, jobs, info)) > 0)
		return (execute_node(node->right, jobs, info));
	return (ret);
}
