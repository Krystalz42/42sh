/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_togo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 10:33:09 by aroulin           #+#    #+#             */
/*   Updated: 2017/08/22 10:33:37 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

int			my_tobackto(int li, int co)
{
	if (li >= 0)
		while (li)
		{
			MV_TOP;
			li--;
		}
	if (co >= 0)
		while (co)
		{
			MV_LEFT;
			co--;
		}

	return (1);
}

int			my_togo(int li, int co)
{
	if (li >= 0)
		while (li)
		{
			MV_BOT;
			li--;
		}
	if (co >= 0)
		while (co)
		{
			MV_RIGHT;
			co--;
		}
	return (1);
}
