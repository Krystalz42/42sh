/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_term.c                                        :+:      :+:    :+:   */
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

int		init_term(void)
{
	static struct termios old_term;
	static struct termios our_term;

	if (!my_getenv("TERM"))
		add_environment("TERM=vt100");
	if (tgetent(NULL, my_getenv("TERM")) == ERR)
		puterror("tgetent");

	if (!(tcgetattr(STDIN_FILENO, &old_term)))
		keep_term_struct(SAVE_OLD, &old_term);
	if (!(tcgetattr(2, &our_term)) && init_our_term(&our_term))
		keep_term_struct(SAVE_OUR, &our_term);
	return (0);
}