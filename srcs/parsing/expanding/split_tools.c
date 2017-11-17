/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 16:47:30 by jle-quel          #+#    #+#             */
/*   Updated: 2017/11/17 16:49:05 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

/*
*************** PUBLIC *********************************************************
*/

size_t			get_wordlength(char *str)
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

size_t			ft_arraylen(char **argv)
{
	size_t		index;

	index = 0;
	while (argv && argv[index])
		index++;
	return (index);
}
