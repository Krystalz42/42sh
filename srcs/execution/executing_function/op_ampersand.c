/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_ampersand.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 16:19:37 by jle-quel          #+#    #+#             */
/*   Updated: 2017/11/17 16:19:40 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

uint8_t			op_ampersand(t_parsing *node, t_jobs *jobs, int info)
{
	return (execute_node(node->left, jobs, (info ^ FOREGROUND)) +
			execute_node(node->right, jobs, info));
}
