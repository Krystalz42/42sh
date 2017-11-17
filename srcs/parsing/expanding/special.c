/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 20:56:06 by jle-quel          #+#    #+#             */
/*   Updated: 2017/11/17 16:46:44 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

/*
*************** TOOLS **********************************************************
*/

static void		populate(char *new, char *str, char *variable, size_t length)
{
	size_t		index;
	char		*temp;

	index = 0;
	temp = str + (length + 2);
	while (str && *str && length--)
		new[index++] = *str++;
	while (variable && *variable)
		new[index++] = *variable++;
	while (temp && *temp)
		new[index++] = *temp++;
}

/*
*************** PRIVATE ********************************************************
*/

static bool		expansion(char **str, size_t index, char *expand, int to_expand)
{
	char	*variable;
	char	*new;

	if (!ft_strncmp(*str + index, expand, 2))
	{
		variable = ft_itoa(to_expand);
		new = (char *)ft_memalloc(sizeof(char) *
		(ft_strlen(variable) + ft_strlen(*str) + 1));
		populate(new, *str, variable, index);
		ft_memdel((void **)&variable);
		ft_memdel((void **)str);
		*str = new;
		return (true);
	}
	return (false);
}

/*
*************** PUBLIC *********************************************************
*/

void			special(t_parsing *node, char *expand, int to_expand)
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
			else
			{
				if (expansion(&node->input, index, expand, to_expand))
					special(temp, expand, to_expand);
				else
					index += 1;
			}
		}
		node = node->next;
	}
}
