/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_tgetnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 16:36:17 by gbourson          #+#    #+#             */
/*   Updated: 2017/11/17 16:36:44 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

int			tgetco(void)
{
	struct winsize ms;

	ioctl(0, TIOCGWINSZ, &ms);
	return (ms.ws_col);
}

int			tgetli(void)
{
	struct winsize ms;

	ioctl(0, TIOCGWINSZ, &ms);
	return (ms.ws_row);
}
