/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_stdin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 22:42:45 by aroulin           #+#    #+#             */
/*   Updated: 2017/08/10 01:30:46 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

t_read			*read_stdin(void)
{
	char		buffer;
	t_read		*read_std = 0;
	
	while (read(STDIN_FILENO, &buffer, sizeof(char)))
	{
		NBR(buffer);
		CHAR(' ');
		if (buffer == 13)
			break;
	}
	return (read_std);
}
