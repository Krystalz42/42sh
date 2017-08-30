/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initTerm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 00:26:38 by aroulin           #+#    #+#             */
/*   Updated: 2017/08/13 06:21:28 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

int		init_our_term(struct termios *term)
{
	(*term).c_lflag &= ~(ICANON);
	(*term).c_lflag &= ~(ECHO);
	(*term).c_cc[VMIN] = 1;
	(*term).c_cc[VTIME] = 0;
	return (1);
}

int		initTerm(void)
{
	static struct termios old_term;
	static struct termios our_term;

	if ((initFd() == -1))
		return (1);
	if (myGetenv("TERM") && tgetent(NULL, myGetenv("TERM")))
	{
		tcgetattr(STDIN_FILENO, &old_term);
		keepTermStruct(SAVE_OLD, &old_term);
	}
	else if (!tgetent(NULL, myGetenv("TERM")))
	{
		addListEnv("TERM", "xterm");
		tcgetattr(STDIN_FILENO, &old_term);
		keepTermStruct(SAVE_OLD, &old_term);
	}
	if (!(tcgetattr(initFd(), &our_term)) && init_our_term(&our_term))
		keepTermStruct(SAVE_OUR, &our_term);
	return (0);
}
