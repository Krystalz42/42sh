/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_del.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 06:33:09 by aroulin           #+#    #+#             */
/*   Updated: 2017/08/19 20:22:27 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

int			key_del(t_read **read_std)
{
	t_cmd		*kill;

	if ((*read_std)->cmd->prev)
	{
		kill = (*read_std)->cmd->prev;
		if ((*read_std)->cmd->prev->prev)
		{
			(*read_std)->cmd->prev->prev->next = (*read_std)->cmd;
			(*read_std)->cmd->prev = (*read_std)->cmd->prev->prev;
		}
		else
			(*read_std)->cmd->prev = NULL;
		ft_memdel((void **)&(kill));
	}
	return (1);
}
