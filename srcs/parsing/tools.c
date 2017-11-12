/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:47:53 by jle-quel          #+#    #+#             */
/*   Updated: 2017/11/11 11:30:38 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

/*
*************** PUBLIC *********************************************************
*/

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
		if (c == '\'' && !(*status & DQUOTE))
			*status = *status & QUOTE ? DEFAULT : QUOTE;
		else if (c == '\"' && !(*status & QUOTE))
			*status = *status & DQUOTE ? DEFAULT : DQUOTE;
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
			*status = SLASH;
			index = 1;
		}
		else if (index == 0)
			*status = DEFAULT;
		else
			index--;
	}
	return (*status);
}

size_t			get_length(char *str)
{
	size_t		index;
	uint8_t		quote;
	uint8_t		slash;

	index = 0;
	quote = DEFAULT;
	slash = DEFAULT;
	while (str[index])
	{
		if (chk_slash(str[index], &slash) == DEFAULT)
		{
			if (chk_quote(str[index], &quote) == DEFAULT && str[index] == ' ')
				break ;
		}
		index++;
	}
	return (index);
}

char			*populating(char *new, char *str, size_t length)
{
	size_t		index;
	uint8_t		quote;

	index = 0;
	quote = DEFAULT;
	while (*str && length--)
	{
		chk_quote(*str, &quote);
		if (*str == '\\' && !(quote & QUOTE))
			;
		else
			new[index++] = *str;
		str++;
	}
	return (str);
}
