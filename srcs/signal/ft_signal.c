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


void				handler_sig(int sig)
{
	log_warn("Signal Reception [%d]", sig);
	set_termios(SET_OLD_TERM);
	exit(sig + 128);
}

void				handler_sigint(int sig)
{
	log_warn("Signal Reception [%d]", sig);
	signal_reception(SIGINT);
	ioctl(0, TIOCSTI, "\2\0");
}

void				handler_sigwinsz(int sig)
{
	log_warn("Signal Reception [%d]", sig);
	ioctl(0, TIOCSTI, "\0");
}

void				init_signal(void)
{
	int i = -1;

	while (++i < 32)
		signal(i, handler_sig);
	signal(SIGINT, &handler_sigint);
	signal(3, SIG_IGN);
	signal(18, SIG_IGN);
	signal(28, &handler_sigwinsz);
	signal(SIGCHLD, &handler_sigchld);

}

void				reset_signal(void)
{
	int i = -1;

	while (++i < 32)
		signal(i, SIG_DFL);
}