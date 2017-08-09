/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_term.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 00:26:38 by aroulin           #+#    #+#             */
/*   Updated: 2017/08/10 01:37:34 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

struct termios		init_my_term(void)
{
	struct termios term;

	term.c_lflag &= ~ICANON;
	term.c_lflag &= ~(ECHO | ECHOE | ECHOK | ECHONL);
	term.c_cc[VTIME] = 0;
	term.c_cc[VMIN] = 1;
	return (term);
}

int		init_term(void)
{
	static struct termios term;
	static struct termios my_term;

	if ((init_fd() == -1))
		return (1);
	if (!(tcgetattr(init_fd(), &term)))
		keep_term_struct(SAVE_OLD, &term);
	my_term = init_my_term();
	keep_term_struct(SAVE_OUR, &term);
	if ((tcsetattr(init_fd(), TCSADRAIN, &my_term)))
		return (1);
	return (0);
}
