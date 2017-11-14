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
	{
		signal(i, handler_sig);
		if (i == SIGCHLD)
			signal(i, handler_sigchld);
		else if (i == SIGINT)
			signal(i, handler_sigint);
	}
	signal(3, SIG_DFL);
	signal(11, SIG_DFL);
	signal(28, &handler_sigwinsz);
}

void				reset_signal(void)
{
	int i = -1;

	while (++i < 32)
		signal(i, SIG_DFL);
}