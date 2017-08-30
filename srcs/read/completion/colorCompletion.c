/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colorCompletion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 13:09:17 by aroulin           #+#    #+#             */
/*   Updated: 2017/08/23 17:36:17 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

void		colorCompletion(unsigned char type, int color)
{
	if (color)
	{
		if (type & DT_DIR)
			STR_FD("\033[1m\x1B[31m", initFd());
		else if (type & DT_BLK)
			STR_FD("\033[1m\x1B[36m", initFd());
		else if (type & DT_CHR)
			STR_FD("\033[1m\x1B[33m", initFd());
		else if (type == DT_LNK)
			STR_FD("\033[1m\x1B[35m", initFd());
	}
}

void		addLittleChar(unsigned char type)
{
	if (type == DT_DIR)
		CHAR_FD('/', initFd());
	else if (type == DT_CHR)
		CHAR_FD('%', initFd());
	else if (type == DT_LNK)
		CHAR_FD('@', initFd());
	else if (type == DT_BLK)
		CHAR_FD('#', initFd());
}
