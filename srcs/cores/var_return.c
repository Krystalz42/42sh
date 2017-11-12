/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_return.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 15:24:17 by aroulin           #+#    #+#             */
/*   Updated: 2017/09/23 19:28:56 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

uint8_t		var_return(int ret)
{
	static uint8_t		save;

	if (ret >= 0 && ret <= UCHAR_MAX)
	{
		save = (uint8_t)ret;
		log_debug("%d", save);
	}
	return (save);
}
