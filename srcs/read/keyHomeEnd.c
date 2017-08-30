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

int			home_key(t_read **read_std)
{
	while ((*read_std)->cmd->prev)
	{
		if (!(*read_std)->history && (*read_std)->cmd->prev->c == 10)
			break ;
		(*read_std)->cmd = (*read_std)->cmd->prev;
	}
	return (1);
}
int			end_key(t_read **read_std)
{
	while ((*read_std)->cmd->next)
		(*read_std)->cmd = (*read_std)->cmd->next;
	return (1);
}
