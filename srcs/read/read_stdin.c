/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_stdin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 22:42:45 by aroulin           #+#    #+#             */
/*   Updated: 2017/08/10 00:24:19 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

t_read			*read_stdin(void)
{
	char		buffer;
	t_read		*read_std = 0;
	
	while (read(STDIN_FILENO, &buffer, sizeof(char)))
	{
		NL;
		CHAR(buffer);
	}
	return (read_std);
}
