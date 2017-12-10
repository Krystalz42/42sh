/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_clear.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 17:29:16 by gbourson          #+#    #+#             */
/*   Updated: 2017/11/17 17:29:36 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

int			key_clear_(t_read **read_std, unsigned long buff)
{
	tputs(tgetstr(CLEAR, 0), STDIN_FILENO, &my_put);
	ft_putchar_fd(10, STDERR_FILENO);
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
