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

int 			prompt(unsigned char flags)
{
	static char		*prompt;
    static int      def;

	if (flags & HEREDOC && (def = 1))
		prompt = "heredoc > ";
	else if (flags & DQUOTE && (def = 1))
		prompt = "dquote > ";
	else if (flags & QUOTE && (def = 1))
		prompt = "quote > ";
	else if (flags & NEXTCMD && (def = 1))
		prompt = "nextcmd > ";
	else if (flags & DEFAULT && !(def = 0))
		prompt = my_prompt(NULL);
	if (flags & PRINT)
		STR_FD(prompt, 2);
	return (!def ? get_len_prompt(-42) : ft_strlen(prompt));
}
