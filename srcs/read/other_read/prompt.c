/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 14:22:37 by aroulin           #+#    #+#             */
/*   Updated: 2017/09/14 15:52:36 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

static inline t_cursor		init_cursor(int len)
{
	t_cursor		cur;
	int				co;

	co = tgetnum("co");
	cur.co = len % co;
	cur.line = (len / co) + 1;
	return (cur);
}

t_cursor					prompt(unsigned char flags)
{
	static char		*prompt;

	if (flags & HEREDOC && get_len_prompt(-1))
		prompt = "heredoc > ";
	else if (flags & DQUOTE && get_len_prompt(-1))
		prompt = "dquote > ";
	else if (flags & QUOTE && get_len_prompt(-1))
		prompt = "quote > ";
	else if (flags & NEXTCMD && get_len_prompt(-1))
		prompt = "nextcmd > ";
	else if (flags & DEFAULT)
		prompt = my_prompt(NULL);
	if (flags & PRINT)
		STR_FD(prompt, 2);
	return (init_cursor((get_len_prompt(-42) == -1) ? (int)ft_strlen(prompt) :
	        get_len_prompt(-42)));
}