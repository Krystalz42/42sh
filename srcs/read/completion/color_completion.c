/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_completion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 13:09:17 by aroulin           #+#    #+#             */
/*   Updated: 2017/08/19 14:17:18 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

void		color_completion(unsigned char type, int color)
{
	if (color)
	{
		if (type & DT_DIR)
			STR_FD("\033[1m\x1B[31m", init_fd());
		else if (type & DT_BLK)
			STR_FD("\033[1m\x1B[36m", init_fd());
		else if (type & DT_CHR)
			STR_FD("\033[1m\x1B[33m", init_fd());
		else if (type == DT_LNK)
			STR_FD("\033[1m\x1B[35m", init_fd());
	}
}

void		add_little_char(unsigned char type)
{
	if (type == DT_DIR)
		CHAR_FD('/', init_fd());
	else if (type == DT_CHR)
		CHAR_FD('%', init_fd());
	else if (type == DT_LNK)
		CHAR_FD('@', init_fd());
	else if (type == DT_BLK)
		CHAR_FD('#', init_fd());
}
