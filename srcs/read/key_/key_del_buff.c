/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_del_buff.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 19:50:10 by aroulin           #+#    #+#             */
/*   Updated: 2017/11/17 17:28:49 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

int		key_del_buff(t_read **read_std, unsigned long buff)
{
	t_outstanding *tmp;

	(void)buff;
	tmp = get_os_pointer(NULL, 0);
	while (tmp->buff)
	{
		key_del(read_std, 0);
		tmp->buff /= (UCHAR_MAX + 1);
	}
	(*read_std)->print = 2;
	return (1);
}
