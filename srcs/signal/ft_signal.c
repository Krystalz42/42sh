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
	if (SIGCHLD == sig)
		jobs_control(SIGNAL_SIGCHLD, new_jobs(-1), sig);
	else
		jobs_control(SIGNAL_RECEPTION, new_jobs(-1), sig);

}

void				init_signal(void)
{
	int i = -1;

	while (++i < 32)
		signal(i, handler_sigint);
	signal(3, SIG_DFL);
	signal(11, SIG_DFL);
}

void				reset_signal(void)
{
	int i = -1;

	while (++i < 32)
		signal(i, SIG_DFL);
}