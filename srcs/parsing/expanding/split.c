/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 18:31:24 by jle-quel          #+#    #+#             */
/*   Updated: 2017/11/09 18:37:45 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

/*
*************** PRIVATE ********************************************************
*/

static size_t	get_numbers(char *str)
{
	size_t		index;
	size_t		numbers;
	uint8_t		status;

	index = split_skip(str);
	numbers = str && str[index] ? 1 : 0;
	status = DEFAULT;
	while (str && str[index])
	{
		chk_quote(str[index], &status);
		if (status & DEFAULT && str[index] == ' ')
		{
			index += split_skip(str + index);
			numbers += str[index] ? 1 : 0;
		}
		else
			index++;
	}
	return (numbers);
}

static char		*get_word(char *str, char **new)
{
	size_t		index;
	size_t		length;
	char		*temp;

	index = split_skip(str);
	length = split_getlength(str + index);
	temp = ft_strsub(str, index, length);
	remove_quote(&temp);
	*new = temp;
	return (str + (index + length));
}

static void		populate(char *str, t_parsing *node)
{
	size_t		index;
	size_t		numbers;

	(void)node;
	index = 0;
	if ((numbers = get_numbers(str)))
	{
		node->command = (char **)ft_memalloc(sizeof(char *) * (numbers + 1));
		while (index < numbers)
			str = get_word(str, &(node->command[index++]));
		node->command[index] = NULL;
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
	uint8_t		rounds;

	rounds = 0;
	while (node)
	{
		if (node->input)
			populate(node->input, node);
		node = node->next;
	}
}
