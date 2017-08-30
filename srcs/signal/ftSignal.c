/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/27 19:16:56 by aroulin           #+#    #+#             */
/*   Updated: 2017/08/27 19:28:21 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

void init_signal(void)
{
	int			i;

	i = -1;
	while (++i < 32)
		signal(i, SIG_IGN);
/*	signal(SIGINT, &);
	signal(SIGTSTP, &handler);
	signal(SIGCONT, &handler);
	signal(SIGQUIT, &handler);
	signal(SIGKILL, &handler);
	signal(SIGSTOP, &handler);
*/}

void reset_signal(void)
{
	int			i;

	i = -1;
	while (++i < 32)
		signal(i, SIG_DFL);
}
