/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_pipe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 15:13:32 by jle-quel          #+#    #+#             */
/*   Updated: 2017/11/17 15:13:35 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

int				read_pipe(int *fildes)
{
	if (fildes)
	{
		log_debug("R[%d][%d] of [%d]", fildes[0], fildes[1], getpid());
		close(fildes[1]);
		dup2(fildes[0], STDIN_FILENO);
		close(fildes[0]);
	}
	return (1);
}

int				write_pipe(int *fildes)
{
	if (fildes)
	{
		log_debug("W[%d][%d] of [%d]", fildes[0], fildes[1], getpid());
		close(fildes[0]);
		dup2(fildes[1], STDOUT_FILENO);
		close(fildes[1]);
	}
	return (1);
}

int				close_pipe(int *fildes)
{
	if (fildes)
	{
		log_debug("C[%d][%d] of [%d]", fildes[0], fildes[1], getpid());
		close(fildes[0]);
		close(fildes[1]);
	}
	return (1);
}