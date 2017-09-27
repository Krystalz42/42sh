/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_del_buff.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 19:50:10 by aroulin           #+#    #+#             */
/*   Updated: 2017/09/25 19:50:11 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

static void     key_delete_buffer(t_read **read_std, unsigned long buff)
{
	t_outstanding *tmp;

	(void)buff;
	tmp = get_os_pointer(NULL, 0);
	while (tmp->buff)
	{
		key_del(read_std, 0);
		tmp->buff /= (UCHAR_MAX + 1);
	}
}

int              key_del_buff(t_read **read_std, unsigned long buff)
{
	if ((*read_std)->completion && bip())
	{
		memdel_completion(&((*read_std)->tab_));
		(*read_std)->print = 2;
	}
	else if ((*read_std)->history_search && bip())
	{
		memdel_lfh(&((*read_std)->hist_search));
		(*read_std)->print = 2;
	}
	else
		key_delete_buffer(read_std, buff);
	return (1);
}