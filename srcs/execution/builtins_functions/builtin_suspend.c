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
	if (node->content->command[1])
	{
		error_msg("suspend: ", TOO_MANY_ARGS, node->content->command[1]);
		return (var_return(1));
	}
	reset_signal();
	set_termios(SET_OLD_TERM);
	kill(getpgid(0), SIGSTOP);
	if (tcgetpgrp(STDIN_FILENO) != getpgid(0))
		builtin_suspend(node, info);
	init_signal();
	set_termios(SET_OUR_TERM);
	return (0);
}
