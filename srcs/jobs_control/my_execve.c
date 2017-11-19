/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_execve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <aroulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 01:04:58 by aroulin           #+#    #+#             */
/*   Updated: 2017/11/19 01:34:48 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

/*
*************** PRIVATE ********************************************************
*/

static void		error(char *str)
{
//	struct stat			buf;
str++;
//	if (lstat(str, &buf) != -1)
//	{
//		if (S_ISDIR(buf.st_mode))
//		{
//			error_msg(S42H, "Is a directory: ", str);
//			exit(var_return(126));
//		}
//		else if (!access(str, F_OK) && access(str, X_OK) == -1)
//		{
//			error_msg(S42H, "Permission denied: ", str);
//			exit(var_return(126));
//		}
//	}
//	else
//	{
//		error_msg(S42H, "command not found: ", str);
		exit(127);
//	}
}

/*
*************** PUBLIC *********************************************************
*/

void			my_execve(char **command, char **env)
{
	reset_signal();
	log_info("[%s] PID [%d] PPID [%d] PGID [%d]",
	command[0], getpid(), getppid(), getpgid(0));
	execve(command[0], command, env) == -1 ? error(command[0]) : 0;
}
