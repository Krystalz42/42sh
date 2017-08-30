/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyDel.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 06:33:09 by aroulin           #+#    #+#             */
/*   Updated: 2017/08/19 20:22:27 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

int			keyDel(t_read **readStd)
{
	t_cmd		*kill;

	if ((*readStd)->cmd->prev)
	{
		kill = (*readStd)->cmd->prev;
		if ((*readStd)->cmd->prev->prev)
		{
			(*readStd)->cmd->prev->prev->next = (*readStd)->cmd;
			(*readStd)->cmd->prev = (*readStd)->cmd->prev->prev;
		}
		else
			(*readStd)->cmd->prev = NULL;
		ft_memdel((void **)&(kill));
	}
	return (1);
}
