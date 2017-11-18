/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 16:31:05 by gbourson          #+#    #+#             */
/*   Updated: 2017/11/17 16:31:51 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

int			refresh_command(t_read **read_std, unsigned long buff)
{
	(void)buff;
	tputs(tgetstr(CLEAR, 0), STDIN_FILENO, &my_put);
	(*read_std)->print = 2;
	return (1);
}
