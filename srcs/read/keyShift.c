/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 06:34:02 by aroulin           #+#    #+#             */
/*   Updated: 2017/08/20 19:54:53 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

int		keyShiftUp(t_read **readStd)
{
	int		co;

	co = tgetnum("co");
	if (co)
		while (co-- && (*readStd)->cmd->prev)
		{
			if (!(*readStd)->history && (*readStd)->cmd->prev->c == 10)
				break ;
			(*readStd)->cmd = (*readStd)->cmd->prev;
		}
	return (1);
}

int		keyShiftDown(t_read **readStd)
{
	int		co;

	co = tgetnum("co");
	if (co)
		while (co-- && (*readStd)->cmd->next)
			(*readStd)->cmd = (*readStd)->cmd->next;
	return (1);
}

int		keyShiftLeft(t_read **readStd)
{
	while ((*readStd)->cmd->prev && (*readStd)->cmd->prev->c == 32)
		(*readStd)->cmd = (*readStd)->cmd->prev;
	while ((*readStd)->cmd->prev)
	{
		if ((*readStd)->cmd->prev->c == 32)
			break;
		(*readStd)->cmd = (*readStd)->cmd->prev;
	}
	return (1);
}

int		keyShiftRight(t_read **readStd)
{

	while ((*readStd)->cmd->c)
	{
		if ((*readStd)->cmd->c == 32)
			break;
		(*readStd)->cmd = (*readStd)->cmd->next;
	}
	while ((*readStd)->cmd->c && (*readStd)->cmd->c == 32)
		(*readStd)->cmd = (*readStd)->cmd->next;
	return (1);
}

