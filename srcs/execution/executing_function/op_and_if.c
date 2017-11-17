/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_and_if.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 16:18:40 by jle-quel          #+#    #+#             */
/*   Updated: 2017/11/17 16:18:43 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

uint8_t			op_and_if(t_node *node, t_jobs *jobs, int info)
{
	uint8_t			ret;

	if ((ret = execute_node(node->left, jobs, info)) == 0)
		return (execute_node(node->right, jobs, info));
	return (ret);
}
