/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrow.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 03:27:42 by aroulin           #+#    #+#             */
/*   Updated: 2017/08/20 16:54:49 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

int			arrow_left(t_read **read_std)
{
	if ((*read_std)->completion)
	{
		back_completion(read_std);
		(*read_std)->completion++;
	}
	else
		if ((*read_std)->cmd->prev)
			if ((*read_std)->history ||
					(!(*read_std)->history && (*read_std)->cmd->prev->c != 10))
				(*read_std)->cmd = (*read_std)->cmd->prev;
	return (1);
}

int			arrow_right(t_read **read_std)
{
	if ((*read_std)->completion)
	{
		continue_completion(read_std);
		(*read_std)->completion++;
	}
	else
		if ((*read_std)->cmd->next)
			(*read_std)->cmd = (*read_std)->cmd->next;

	return (1);
}

int			arrow_up(t_read **read_std)
{
	if ((*read_std)->completion)
	{
		SAVE;
		MV_BOT;
		P_RST_FD(init_fd());
		to_up(read_std, 0, 0);
		(*read_std)->completion++;
		RESTORE;
	}
	else
		;
	return (1);
}

int			arrow_down(t_read **read_std)
{
	if ((*read_std)->completion)
	{
		SAVE;
		MV_BOT;
		P_RST_FD(init_fd());
		to_down(read_std);
		(*read_std)->completion++;
		RESTORE;
	}
	else
		;
	return (1);
}
