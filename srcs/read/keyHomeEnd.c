/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   home_end.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 06:30:22 by aroulin           #+#    #+#             */
/*   Updated: 2017/08/20 17:26:09 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

int			keyHome(t_read **readStd)
{
	while ((*readStd)->cmd->prev)
	{
		if (!(*readStd)->history && (*readStd)->cmd->prev->c == 10)
			break ;
		(*readStd)->cmd = (*readStd)->cmd->prev;
	}
	return (1);
}
int			keyEnd(t_read **readStd)
{
	while ((*readStd)->cmd->next)
		(*readStd)->cmd = (*readStd)->cmd->next;
	return (1);
}
