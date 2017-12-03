/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 11:58:33 by jle-quel          #+#    #+#             */
/*   Updated: 2017/12/02 12:19:09 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

/*
*************** TOOLS **********************************************************
*/

char			*populating(char *new, char *str, size_t length)
{
	size_t		index;
	size_t		i;
	uint8_t		status;

	index = 0;
	i = 0;
	status = DEFAULT;
	while (str[i] && length--)
	{
		if (!(status & BACKSLASH) && str[i] == '\\' && !(status & SINGLE_QUOTE))
			status |= BACKSLASH;
		else if (!(status & BACKSLASH) && status & DEFAULT && isquote(str[i]))
			status = (status | isquote(str[i])) ^ DEFAULT;
		else if (!(status & BACKSLASH) && status & isquote(str[i]))
			status = (status ^ isquote(str[i])) | DEFAULT;
		else
		{
			status & BACKSLASH ? (status ^= BACKSLASH) : 0;
			new[index++] = str[i];
		}
		i++;
	}
	return (str + i);
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

/*
*************** PUBLIC *********************************************************
*/

char			**do_split(char *str)
{
	size_t		index;
	size_t		numbers;
	char		**ret;

	index = 0;
	if ((numbers = get_numbers(str)))
	{
		ret = (char **)ft_memalloc(sizeof(char *) * (numbers + 1));
		while (index < numbers)
			str = get_word(str, &ret[index++]);
	}
	else
	{
		ret = (char **)ft_memalloc(sizeof(char *) * (2));
		ret[0] = (char *)ft_memalloc(sizeof(char));
		ret[1] = NULL;
	}
	return (ret);
}

void			split(t_parsing *node)
{
	while (node)
	{
		if (node->input)
			node->command = do_split(node->input);
		node = node->next;
	}
}
