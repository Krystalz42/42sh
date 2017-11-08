/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_eof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/12 17:38:25 by aroulin           #+#    #+#             */
/*   Updated: 2017/08/20 19:41:02 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

int			key_eof(t_read **read_std, unsigned long buff)
{
	if (!(*read_std)->cmd->c && !(*read_std)->cmd->prev)
	{
		if (get_len_prompt(-42) == -2)
			signal_reception(1);
		else
			exit_();
	}
	else if ((*read_std)->cmd->c)
	{
		key_delete_here(read_std, buff);
		(*read_std)->print = 2;
	}
	return (1);
}