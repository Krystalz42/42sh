/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_great.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 15:19:54 by jle-quel          #+#    #+#             */
/*   Updated: 2017/11/19 01:17:23 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

uint8_t			op_great(t_node *node, t_jobs *jobs, int info)
{
	log_debug("VALUE GREAT %d", info);
	(void)node; (void)jobs; (void)info;
	return (var_return(-1));
}
