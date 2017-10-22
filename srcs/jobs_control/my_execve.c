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
	log_info("Will execute [%s] PID [%d] PPID [%d] PGID [%d] in my_execve ", command[0], getpid(), getppid(), getpgid(0));
	if ((execve(command[0], command, env)) == -1)
		exit(EXIT_FAILURE);
}