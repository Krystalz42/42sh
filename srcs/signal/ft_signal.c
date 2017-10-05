/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/27 19:16:56 by aroulin           #+#    #+#             */
/*   Updated: 2017/09/23 20:05:18 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>


void				handler_sigint(int sig)
{
	(void)sig;
	ioctl(STDIN_FILENO, TIOCSTI, "\x2\x0");
}

void				init_signal(void)
{
	int i = -1;

	while (++i < 32)
		signal(i, SIG_IGN);
	signal(SIGINT, handler_sigint);
}

void				reset_signal(void)
{
int i = -1;

while (++i < 32)
	signal(i, SIG_DFL);
}