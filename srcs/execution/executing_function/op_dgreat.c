/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_dgreat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 16:11:44 by jle-quel          #+#    #+#             */
/*   Updated: 2017/11/19 01:24:23 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

uint8_t			op_dgreat(t_node *node, t_jobs *jobs, int info)
{
	log_debug("VALUE DGREAT %d", info);
	(void)node; (void)jobs; (void)info;
	return (var_return(-1));

}
