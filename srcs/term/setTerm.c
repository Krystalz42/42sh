/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_term.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 19:41:11 by aroulin           #+#    #+#             */
/*   Updated: 2017/08/13 06:22:08 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

void			setTermios(unsigned short flags)
{
	struct termios term;

	if ((flags & SET_OUR_TERM))
	{
		term = keepTermStruct(OUR_TERM, NULL);
		tcsetattr(0, TCSADRAIN, &term);
	}
	if ((flags & SET_OLD_TERM))
	{
		term = keepTermStruct(OLD_TERM, NULL);
		tcsetattr(0, 0, &term);
	}
}
