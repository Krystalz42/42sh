/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_less.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 16:16:43 by jle-quel          #+#    #+#             */
/*   Updated: 2017/11/19 12:05:03 by sbelazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

uint8_t			op_less(t_node *node, t_jobs *jobs, int info)
{
	log_debug("VALUE_LESS %d", info);
	(void)node;
	(void)jobs;
	(void)info;
	return (var_return(-1));
}
