/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_completion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/13 03:59:11 by aroulin           #+#    #+#             */
/*   Updated: 2017/08/16 20:17:31 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

int			empty_cmd(t_cmd *cmd)
{
	if (!cmd->prev)
		return (1);
	cmd = cmd->prev;
	while (cmd->prev)
	{
		if (cmd->c != 32 && cmd->c != 0 && cmd->c != 9)
			return (0);
		cmd = cmd->prev;
	}
	return (1);
}

void		init_completion(t_read **read_std)
{
	if (empty_cmd((*read_std)->cmd))
		key_print_(read_std, 9);
	else
		completion(read_std);
}
