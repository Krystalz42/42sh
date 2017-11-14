/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_execve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 01:04:58 by aroulin           #+#    #+#             */
/*   Updated: 2017/10/06 01:05:01 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

void			my_execve(char **command, char **env)
{
	reset_signal();
	log_info("[%s] PID [%d] PPID [%d] PGID [%d]",
			command[0], getpid(), getppid(), getpgid(0));
	int i = -1;
	while (command[++i])
		log_debug("%s", command[i]);
	if ((execve(command[0], command, env)) == -1)
	{
		error_msg("42sh: ", "command not found: ", command[0]);
		exit(127);
	}
}