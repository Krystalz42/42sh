/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_execve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <aroulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 01:04:58 by aroulin           #+#    #+#             */
/*   Updated: 2017/11/30 15:08:25 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

/*
*************** PRIVATE ********************************************************
*/

static void		error(char *str)
{
	struct stat			buf;

	if (lstat(str, &buf) != -1)
	{
		if (S_ISDIR(buf.st_mode) || S_ISLNK(buf.st_mode))
			error_msg(S42H, "is a directory: ", str);
		else if (!access(str, F_OK) && access(str, X_OK) == -1)
			error_msg(S42H, "permission denied: ", str);
		exit(var_return(126));
	}
	else
	{
		if (ft_strchr(str, '/'))
			error_msg(S42H, "no such file or directory: ", str);
		else
			error_msg(S42H, "command not found: ", str);
		exit(var_return(126));
	}
}

/*
*************** PUBLIC *********************************************************
*/

void			my_execve(char **command, char **env)
{
	reset_signal();
	execve(command[0], command, env);
	error(command[0]);
}
