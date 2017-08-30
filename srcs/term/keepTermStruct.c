/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_term.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 00:54:26 by aroulin           #+#    #+#             */
/*   Updated: 2017/08/11 00:01:53 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

struct termios		keepTermStruct(unsigned short flags, struct termios *term)
{
	static struct termios		*save_our_term;
	static struct termios		*save_old_term;
	static struct termios		null;

	if ((flags & SAVE_OLD))
		save_old_term = term;
	else if ((flags & SAVE_OUR))
		save_our_term = term;
	if ((flags & OLD_TERM))
		return (*save_old_term);
	else if ((flags & OUR_TERM))
		return (*save_our_term);
	return (null);
}
