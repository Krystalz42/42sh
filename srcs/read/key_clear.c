/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_clear_.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/12 17:44:04 by aroulin           #+#    #+#             */
/*   Updated: 2017/08/19 21:05:17 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

int			key_clear_(t_read **read_std, unsigned long buff)
{
	CLEAR;
	(void)buff;
	(*read_std)->print = 2;
	return (1);
}
