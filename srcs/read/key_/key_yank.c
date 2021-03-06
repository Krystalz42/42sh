/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_yank.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 20:13:21 by aroulin           #+#    #+#             */
/*   Updated: 2017/11/17 16:46:31 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

int			key_yank(t_read **read_std, unsigned long buff)
{
	t_cmd			*buffer;

	(void)buff;
	buffer = keep_buffer(NULL, 0);
	while (buffer)
	{
		key_print_fct((*read_std)->cmd, buffer->c);
		buffer = buffer->next;
	}
	(*read_std)->print = 2;
	return (1);
}
