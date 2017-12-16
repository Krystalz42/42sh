/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_suspend.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 15:22:47 by aroulin           #+#    #+#             */
/*   Updated: 2017/12/13 15:47:35 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

int				suspend_jobs(void)
{
	char			*shlvl;

	if ((shlvl = my_getenv("SHLVL")))
		if (ft_atoi(shlvl) > 0)
			return (1);
	error_msg(S42H, "Can't suspend parent shell.", NULL);
	return (0);
}

uint8_t			builtin_suspend(t_parsing *node, int info)
{
	(void)node;
	(void)info;
	if (node->command[1])
	{
		error_msg("suspend: ", TOO_MANY_ARGS, node->command[1]);
		return (var_return(1));
	}
	if (suspend_jobs() == 0)
		return (0);
	reset_signal();
	set_termios(SET_OLD_TERM);
	kill(getpgid(0), SIGSTOP);
	if (tcgetpgrp(STDIN_FILENO) != getpgid(0))
		builtin_suspend(node, info);
	init_signal();
	set_termios(SET_OUR_TERM);
	return (0);
}
