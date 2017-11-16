/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 17:58:20 by jle-quel          #+#    #+#             */
/*   Updated: 2017/11/16 18:13:28 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

/*
*************** TOOLS **********************************************************
*/

static char		*get_variable(char *str)
{
	size_t		skip;
	size_t		index;
	char		*new;

	skip = 0;
	while (str && str[skip])
	{
		if (str[skip] != '$')
			break ;
		skip++;
	}
	index = skip;
	while (str && str[index])
	{
		if (str[index] == '\"' || str[index] == ' ' || str[index] == '/')
			break ;
		index++;
	}
	new = index > skip ? ft_strsub(str, skip, index - skip) : NULL;
	return (new);
}

static void		populate(char *new, char *str, char *variable, size_t length)
{
	size_t		index;

	index = 0;
	while (str && *str && length--)
		new[index++] = *str++;
	while (variable && *variable)
		new[index++] = *variable++;
	while (str && *str && *str == '$')
		str++;
	while (str && *str && *str != '\"' && *str != ' ' && *str != '/')
		str++;
	while (str && *str)
		new[index++] = *str++;
}

/*
*************** PRIVATE ********************************************************
*/

static bool		expansion(char **str, size_t index)
{
	char		*memory;
	char		*variable;
	char		*new;

	memory = get_variable(*str + index);
	if (memory)
	{
		variable = my_getenv(memory);
		new = (char *)ft_memalloc(sizeof(char) * (ft_strlen(*str) + ft_strlen(variable) + 1));
		populate(new, *str, variable, index);
		ft_memdel((void **)str);
		ft_memdel((void **)&memory);
		*str = new;
		return (true);
	}
	return (false);
}

/*
*************** PUBLIC *********************************************************
*/

void			variable(t_parsing *node)
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
				if (node->input[index] == '$' && expansion(&node->input, index))
					variable(temp);
				else
					index += 1;
			}
		}
		node = node->next;
	}
}
