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
	tputs(tgetstr(CLEAR, 0), STDIN_FILENO, &my_put);
	(void)buff;
	if ((*read_std)->completion)
	{
		memdel_completion(&((*read_std)->tab_));
		(*read_std)->print = 2;
	}
	else if ((*read_std)->history_search)
	{
		memdel_lfh(&((*read_std)->hist_search));
		(*read_std)->print = 2;
	}
	else
		(*read_std)->print = 2;
	return (1);
}
