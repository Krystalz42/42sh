/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   restore_cursor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 14:53:09 by aroulin           #+#    #+#             */
/*   Updated: 2017/09/06 14:53:11 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

void		restore_cursor_(t_cursor cur)
{
	tputs(tgetstr(BACK_N, 0), STDIN_FILENO, &my_put);
	while (--cur.co > 0)
		tputs(tgetstr(MV_LEFT, 0), 0, &my_put);
	while (--cur.line > 0)
		tputs(tgetstr(MV_TOP, 0), STDIN_FILENO, &my_put);
}