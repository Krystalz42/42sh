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

int			key_home_(t_read **read_std, unsigned long buff)
{
	if ((*read_std)->history_search && bip() && ((*read_std)->print = 2))
		return (0);
	else if ((*read_std)->completion && bip())
		(*read_std)->print = 2;
	else if ((*read_std)->cmd->prev)
	{
		add_outstanding(NULL, buff, 0);
		while ((*read_std)->cmd->prev)
		{
			if (!(*read_std)->history && (*read_std)->cmd->prev->c == 10)
				break ;
			(*read_std)->cmd = (*read_std)->cmd->prev;
		}
		(*read_std)->print = 2;
	}
	else
		bip();
	return (1);
}
int			key_end_(t_read **read_std, unsigned long buff)
{
	if ((*read_std)->history_search && bip() && ((*read_std)->print = 2))
		return (0);
	else if ((*read_std)->completion && bip())
		(*read_std)->print = 2;
	else if ((*read_std)->cmd->next)
	{
		add_outstanding(NULL, buff, 0);
		while ((*read_std)->cmd->next)
			(*read_std)->cmd = (*read_std)->cmd->next;
		(*read_std)->print = 2;
	}
	else
		bip();
	return (1);
}
