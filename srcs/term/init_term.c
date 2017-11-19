/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_term.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 00:26:38 by aroulin           #+#    #+#             */
/*   Updated: 2017/11/17 16:08:50 by gbourson         ###   ########.fr       */
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
	static struct termios	old_term;
	static struct termios	our_term;
	int						ret;

	ret = 0;
	if (!my_getenv("TERM"))
		add_environment("TERM=vt100");
	if ((tgetent(NULL, my_getenv("TERM"))) == ERR)
		ret = 1;
	if (tcgetpgrp(0) != getpgid(0))
		log_success("C D LUNIX");
	if (!(tcgetattr(init_fd(), &old_term)))
		keep_term_struct(SAVE_OLD, &old_term);
	if (!(tcgetattr(init_fd(), &our_term)) && init_our_term(&our_term))
		keep_term_struct(SAVE_OUR, &our_term);
	if (ret)
	{
		error_msg("termios : ", "can't be initialize\n", NULL);
		exit(255);
	}
	return (0);
}
