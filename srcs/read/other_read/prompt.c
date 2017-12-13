/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 14:22:37 by aroulin           #+#    #+#             */
/*   Updated: 2017/11/17 16:23:38 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

static inline t_cursor		init_cursor(int len)
{
	t_cursor		cur;
	int				co;

	if ((co = tgetco()) > 0)
	{
		cur.co = len % co;
		cur.line = (len / co) + 1;
		return (cur);
	}
	return ((t_cursor){0, 0, 0});
}

t_cursor					prompt(unsigned char flags)
{
	static char		*prompt;

	if (flags & HEREDOC && get_len_prompt(KEEP))
		prompt = "heredoc > ";
	else if (flags & DQUOTE && get_len_prompt(MORE))
		prompt = "dquote > ";
	else if (flags & QUOTE && get_len_prompt(MORE))
		prompt = "quote > ";
	else if (flags & NEXTCMD && get_len_prompt(MORE))
		prompt = "nextcmd > ";
	else if (flags & DEFAULT)
		prompt = my_prompt(NULL);
	if (flags & PRINT)
		STR_FD(prompt, 2);
	return (init_cursor((get_len_prompt(-42) < 0) ? (int)ft_strlen(prompt) :
			get_len_prompt(-42)));
}
