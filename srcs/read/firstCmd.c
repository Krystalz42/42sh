/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   firstCmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/13 05:46:50 by aroulin           #+#    #+#             */
/*   Updated: 2017/08/20 10:52:59 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

t_cmd			*firstCmd(t_cmd *cmd, int history)
{
	if (cmd)
		while (cmd->next)
			cmd = cmd->next;
	while (cmd->prev)
	{
		if (!history && cmd->prev->c == 10)
			return (cmd);
		cmd = cmd->prev;
	}
	return (cmd);
}
