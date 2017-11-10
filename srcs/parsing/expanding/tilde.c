/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tilde.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 12:25:28 by jle-quel          #+#    #+#             */
/*   Updated: 2017/11/10 21:29:48 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

/*
*************** TOOLS **********************************************************
*/

static void		populate(char *new, char *str, char *home, size_t length)
{
	size_t		index;
	char		*temp;

	index = 0;
	temp = str + (length + 1);
	while (str && *str && length--)
		new[index++] = *str++;
	while (home && *home)
		new[index++] = *home++;
	while (temp && *temp)
		new[index++] = *temp++;
}

/*
*************** PRIVATE ********************************************************
*/

static bool		chk(const char *str, size_t index)
{
	if (index == 0 || !str[index - 1] || str[index - 1] == ' ')
	{
		if (!str[index + 1] || str[index + 1] == ' ' || str[index + 1] == '/')
		{
			if (str[index] == '~')
				return (true);
		}
	}
	return (false);
}

static bool		expansion(char **str, size_t index)
{
	char		*home;
	char		*new;

	home = my_getenv("HOME=");
	if (home && ft_strlen(home))
	{
		new = (char *)ft_memalloc(sizeof(char) * (ft_strlen(*str) + ft_strlen(home) + 1));
		populate(new, *str, home, index);
		ft_memdel((void **)str);
		*str = new;
		return (true);
	}
	return (false);
}

/*
*************** PUBLIC *********************************************************
*/

void			tilde(t_parsing *node)
{
	size_t		index;
	uint8_t		status;
	t_parsing	*temp;
	
	status = DEFAULT;
	temp = node;
	while (node)
	{
		index = 0;
		while (node->input && node->input[index])
		{
			chk_quote(node->input[index], &status);
			if (status & DEFAULT && chk(node->input, index) && expansion(&node->input, index))
				tilde(temp);
			index++;
		}
		node = node->next;
	}
}
