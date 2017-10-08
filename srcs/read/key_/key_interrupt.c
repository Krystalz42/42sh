/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_interrupt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/12 17:42:48 by aroulin           #+#    #+#             */
/*   Updated: 2017/09/24 15:24:34 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

int			key_interrupt(t_read **read_std, unsigned long buff)
{
	(void)buff;
	var_return(1);
	(*read_std)->finish = 2;
	(*read_std)->print = 2;
	return (1);
}
