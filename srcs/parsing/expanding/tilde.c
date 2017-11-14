/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tilde.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 21:33:52 by jle-quel          #+#    #+#             */
/*   Updated: 2017/11/14 11:25:35 by jle-quel         ###   ########.fr       */
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
	t_parsing	*temp;

	temp = node;
	while (node)
	{
		index = 0;
		while (node->input && node->input[index])
		{
			if (node->input[index] == '\\')
				index += 2;
			else if (node->input[index] == '\'')
				index += skip_to_occurence(node->input + index, '\'');
			else if (node->input[index] == '\"')
				index += skip_to_occurence(node->input + index, '\"');
			else
			{
				if (chk(node->input, index) && expansion(&node->input, index))
					tilde(temp);
				else
					index++;
			}
		}
		node = node->next;
	}
}
