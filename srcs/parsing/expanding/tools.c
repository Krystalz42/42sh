/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:47:53 by jle-quel          #+#    #+#             */
/*   Updated: 2017/11/17 16:48:17 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

/*
*************** PUBLIC *********************************************************
*/

size_t			skip_to_occurence(char *str, char c)
{
	size_t		index;
	uint8_t		occurence;

	index = 0;
	occurence = 0;
	while (str && str[index] && occurence < 2)
	{
		occurence += str[index] == c ? 1 : 0;
		index++;
	}
	return (index);
}

char			*do_skip(char *str, char c)
{
	while (*str && *str == c)
		str++;
	return (str);
}

uint8_t			chk_quote(char c, uint8_t *status)
{
	if (c)
	{
		if (c == '\'' && !(*status & DOUBLE_QUOTE))
			*status = *status & SINGLE_QUOTE ? DEFAULT : SINGLE_QUOTE;
		else if (c == '\"' && !(*status & SINGLE_QUOTE))
			*status = *status & DOUBLE_QUOTE ? DEFAULT : DOUBLE_QUOTE;
	}
	return (*status);
}

uint8_t			chk_slash(char c, uint8_t *status)
{
	static int	index;

	if (c)
	{
		if (c == '\\' && *status & DEFAULT)
		{
			*status = BACKSLASH;
			index = 1;
		}
		else if (index == 0)
			*status = DEFAULT;
		else
			index--;
	}
	return (*status);
}

int				isquote(char c)
{
	if (c == '\'')
		return (SINGLE_QUOTE);
	if (c == '\"')
		return (DOUBLE_QUOTE);
	return (0);
}
