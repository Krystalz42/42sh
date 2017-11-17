/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_refresh.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 16:51:07 by gbourson          #+#    #+#             */
/*   Updated: 2017/11/17 16:51:29 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

int		key_refresh_(t_read **read_std, unsigned long buff)
{
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
