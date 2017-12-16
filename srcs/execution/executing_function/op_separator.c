/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_separator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 15:21:55 by jle-quel          #+#    #+#             */
/*   Updated: 2017/11/17 15:22:00 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

uint8_t				op_separator(t_parsing *node, t_jobs *jobs, int info)
{
	return (execute_node(node->left, jobs, info) +
			execute_node(node->right, jobs, info));
}
