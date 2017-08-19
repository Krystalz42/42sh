/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 14:22:37 by aroulin           #+#    #+#             */
/*   Updated: 2017/08/19 14:55:45 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>



int 			prompt(unsigned char flags, char *str)
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
		prompt = str;
	if (!(flags & PRINT))
		STR_FD(prompt, init_fd());
	return (ft_strlen(prompt));
}
