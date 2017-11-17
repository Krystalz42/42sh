/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_togo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 10:33:09 by aroulin           #+#    #+#             */
/*   Updated: 2017/11/17 17:33:44 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

int			my_tobackto(int li, int co)
{
	if (li >= 0)
		while (li)
		{
			tputs(tgetstr(MV_TOP, 0), STDIN_FILENO, &my_put);
			li--;
		}
	if (co >= 0)
		while (co)
		{
			tputs(tgetstr(MV_LEFT, 0), STDIN_FILENO, &my_put);
			co--;
		}
	return (1);
}

int			my_togo(int li, int co)
{
	if (li >= 0)
		while (li)
		{
			tputs(tgetstr(MV_BOT, 0), STDIN_FILENO, &my_put);
			li--;
		}
	if (co >= 0)
		while (co)
		{
			tputs(tgetstr(MV_RIGHT, 0), STDIN_FILENO, &my_put);
			co--;
		}
	return (1);
}
