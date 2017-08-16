/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrow.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 03:27:42 by aroulin           #+#    #+#             */
/*   Updated: 2017/08/13 07:08:55 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

int			arrow_left(t_read **read_std)
{
	if ((*read_std)->completion)
		;
	else
		if ((*read_std)->cmd->prev)
			if (!(*read_std)->history ||
					((*read_std)->history && (*read_std)->cmd->prev->c != 10))
				(*read_std)->cmd = (*read_std)->cmd->prev;
	return (1);
}

int			arrow_right(t_read **read_std)
{
	if ((*read_std)->completion)
		;
	else
		if ((*read_std)->cmd->next)
			(*read_std)->cmd = (*read_std)->cmd->next;

	return (1);
}

int			arrow_up(t_read **read_std)
{
	STR("AU\n");
	(void)read_std;
	return (1);
}

int			arrow_down(t_read **read_std)
{
	STR("AD\n");
	(void)read_std;
	return (1);
}
