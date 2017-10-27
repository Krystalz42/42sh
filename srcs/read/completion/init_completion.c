/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_completion.c                                  :+:      :+:    :+:   */
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

void		init_completion(t_read **read_std)
{
	log_trace("%d",check_word((*read_std)->cmd));
	if (check_word((*read_std)->cmd))
	{
		(*read_std)->completion = 2;
		complete_binary(read_std);
	}
	else
	{
		(*read_std)->completion = 2;
		completion(read_std);
	}
}
