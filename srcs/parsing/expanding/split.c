/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 11:58:33 by jle-quel          #+#    #+#             */
/*   Updated: 2017/11/14 11:50:29 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

/*
*************** TOOLS **********************************************************
*/

char			*populating(char *new, char *str, size_t length)
{
	size_t		index;
	uint8_t		status;

	index = 0;
	status = DEFAULT;
	while (*str && length--)
	{
		if (!(status & BACKSLASH) && *str == '\\' && !(status & SINGLE_QUOTE))
			status |= BACKSLASH;
		else if (!(status & BACKSLASH) && status & DEFAULT && isquote(*str))
		{
			status |= isquote(*str);
			status ^= DEFAULT;
		}
		else if (!(status & BACKSLASH) && status & isquote(*str))
		{
			status ^= isquote(*str);
			status |= DEFAULT;
		}
		else
		{
			if (status & BACKSLASH)
				status ^= BACKSLASH;
			if (*str != 10)
				new[index++] = *str;
		}
		str++;
	}
	return (str);
}

static char		*get_word(char *str, char **new)
{
	size_t		length;

	str = do_skip(str, ' ');
	length = get_wordlength(str);
	*new = (char *)ft_memalloc(sizeof(char) * (length + 1));
	str = populating(*new, str, length);
	return (str);
}

/*
*************** PRIVATE ********************************************************
*/

size_t			get_numbers(char *str)
{
	size_t		numbers;
	uint8_t		quote;
	uint8_t		slash;

	str = do_skip(str, ' ');
	numbers = *str ? 1 : 0;
	quote = DEFAULT;
	slash = DEFAULT;
	while (*str)
	{
		if (chk_slash(*str, &slash) == DEFAULT)
		{
			if (chk_quote(*str, &quote) == DEFAULT && *str == ' ')
			{
				str = do_skip(str, ' ');
				numbers += *str ? 1 : 0;
			}
			else
				str++;
		}
		else
			str++;
	}
	return (numbers);
}

static void		do_split(char *str, t_parsing *node)
{
	size_t		index;
	size_t		numbers;

	index = 0;
	if ((numbers = get_numbers(str)))
	{
		node->command = (char **)ft_memalloc(sizeof(char *) * (numbers + 1));
		while (index < numbers)
			str = get_word(str, &node->command[index++]);
	}
	else
	{
		node->command = (char **)ft_memalloc(sizeof(char *) * (2));
		node->command[0] = (char *)ft_memalloc(sizeof(char));
		node->command[1] = NULL;
	}
}

/*
*************** PUBLIC *********************************************************
*/

void			split(t_parsing *node)
{
	while (node)
	{
		if (node->input)
			do_split(node->input, node);
		node = node->next;
	}
}
