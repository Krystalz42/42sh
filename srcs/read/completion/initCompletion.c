/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initCompletion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/13 03:59:11 by aroulin           #+#    #+#             */
/*   Updated: 2017/08/19 14:05:31 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

int			empty_cmd(t_cmd *cmd)
{
	if (!cmd->prev)
		return (1);
	while (cmd->prev)
	{
		cmd = cmd->prev;
		if (cmd->c != 32 && cmd->c != 0 && cmd->c != 9)
			return (0);
	}
	return (1);
}

void		initCompletion(t_read **readStd)
{
	if (empty_cmd((*readStd)->cmd))
		keyPrint(readStd, 9);
	else
	{
		(*readStd)->completion = 2;
		completion(readStd);
	}
}
