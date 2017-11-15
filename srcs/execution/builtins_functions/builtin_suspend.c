/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_suspend.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 15:22:47 by aroulin           #+#    #+#             */
/*   Updated: 2017/10/30 15:22:50 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

uint8_t			builtin_suspend(t_node *node, int info)
{
	(void)node;
	(void)info;
	reset_signal();
	set_termios(SET_OLD_TERM);
	kill(getpgid(0), SIGSTOP);
	init_signal();
	set_termios(SET_OUR_TERM);
	return (0);
}
