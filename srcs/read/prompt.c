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

	if (flags & HEREDOC)
		prompt = "heredoc > ";
	else if (flags & DQUOTE)
		prompt = "dquote > ";
	else if (flags & QUOTE)
		prompt = "quote > ";
	else if (flags & NEXTCMD)
		prompt = "nextcmd > ";
	else if (flags & DEFAULT)
		prompt = my_prompt(NULL);
	if (flags & PRINT)
		STR_FD(prompt, init_fd());
	return (ft_strlen(prompt));
}
