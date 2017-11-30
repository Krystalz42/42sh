/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_term.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 00:26:38 by aroulin           #+#    #+#             */
/*   Updated: 2017/11/20 15:30:10 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

static int		init_our_term(struct termios *term)
{
	(*term).c_lflag &= ~(ICANON);
	(*term).c_lflag &= ~(ECHO);
	(*term).c_cc[VMIN] = 1;
	(*term).c_cc[VTIME] = 0;
	return (1);
}

static void			mine_terminal(int ret)
{
	if (isatty(STDIN_FILENO) == 0)
	{
		error_msg(S42H, "STDIN_FILENO is not a tty.", NULL);
		exit(255);
	}
	if (isatty(STDOUT_FILENO) == 0)
	{
		error_msg(S42H, "STDOUT_FILENO is not a tty.", NULL);
		exit(255);
	}
	if (tcgetpgrp(STDIN_FILENO) != getpgid(0))
	{
		kill(getpgid(0), SIGTTIN);
		mine_terminal(ret);
	}
}

void		we_are_shell(int ret)
{
	if (ret)
	{
		error_msg("termios : ", "can't be initialize\n", NULL);
		exit(255);
	}
	if (tcgetpgrp(STDOUT_FILENO) != getpgid(0))
		kill(getpgid(0), SIGTTOU);
}

int				init_term(void)
{
	static struct termios	old_term;
	static struct termios	our_term;
	static int				ret;

	if (!my_getenv("TERM"))
		add_environment("TERM=vt100");
	if ((tgetent(NULL, my_getenv("TERM"))) == ERR)
		ret = 1;
	if (!(tcgetattr(init_fd(), &old_term)))
		keep_term_struct(SAVE_OLD, &old_term);
	else
		ret = 1;
	if (!(tcgetattr(init_fd(), &our_term)) && init_our_term(&our_term))
		keep_term_struct(SAVE_OUR, &our_term);
	else
		ret = 1;
	mine_terminal(ret);
	return (0);
}
