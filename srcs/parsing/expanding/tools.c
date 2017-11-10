/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 18:32:15 by jle-quel          #+#    #+#             */
/*   Updated: 2017/11/09 18:37:25 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

/*
*************** TOOLS **********************************************************
*/

static void		populate(char *str, char *new)
{
	size_t		index;
	size_t		i;
	uint8_t		status;

	if (str && new)
	{
		index = 0;
		i = 0;
		status = DEFAULT;
		while (str[index])
		{
			chk_quote(str[index], &status);
			if (str[index] == '\"' && status & QUOTE)
				new[i++] = str[index];
			else if (str[index] == '\'' && status & DQUOTE)
				new[i++] = str[index];
			else if (str[index] == '\'' || str[index] == '\"')
				;
			else if (str[index] != 10)
				new[i++] = str[index];
			index++;
		}
	}
}

/*
*************** PUBLIC *********************************************************
*/

size_t			split_skip(char *str)
{
	size_t		index;

	index = 0;
	while (str && str[index])
	{
		if (str[index] != ' ')
			break ;
		index++;
	}
	return (index);
}

size_t			split_getlength(char *str)
{
	size_t		index;
	uint8_t		status;

	index = 0;
	status = DEFAULT;
	while (str[index])
	{
		chk_quote(str[index], &status);
		if (status & DEFAULT && str[index] == ' ')
			break ;
		index++;
	}
	return (index);
}

void			remove_quote(char **str)
{
	char		*new;

	if (*str)
	{
		new = (char *)ft_memalloc(sizeof(char) * (ft_strlen(*str) + 1));
		populate(*str, new);
		ft_memdel((void **)str);
		*str = new;
	}
}
