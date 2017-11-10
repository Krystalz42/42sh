/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 14:17:08 by jle-quel          #+#    #+#             */
/*   Updated: 2017/11/10 16:45:48 by jle-quel         ###   ########.fr       */
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

static char		*populate(char *str, char *variable, size_t length)
{
	size_t		index;
	char		*new;

	index = 0;
	new = (char *)ft_memalloc(sizeof(char) *
									(ft_strlen(str) + ft_strlen(variable) + 1));
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
	return (new);
}

/*
*************** PRIVATE ********************************************************
*/

static bool		expansion(char **str, size_t index)
{
	char		*temp;
	char		*memory;
	char		*variable;
	char		*new;

	memory = get_variable(*str + index);
	if (memory)
	{
		temp = ft_strjoin(memory, "=");
		ft_memdel((void **)&memory);
		variable = my_getenv(temp);
		ft_memdel((void **)&temp);
		new = populate(*str, variable, index); 
		ft_memdel((void **)str);
		*str = new;
		return (true);
	}
	return (false);
}

/*
*************** PUBLIC *****************************************************
*/

void			variable(t_parsing *node)
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
			if (status & (DEFAULT | DQUOTE) && node->input[index] == '$'
				&& expansion(&node->input, index))
				variable(temp);
			index++;
		}
		node = node->next;
	}
}
