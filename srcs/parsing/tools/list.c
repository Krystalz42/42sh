/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:58:31 by jle-quel          #+#    #+#             */
/*   Updated: 2017/11/09 18:19:06 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

/*
*************** PUBLIC *********************************************************
*/

t_parsing		*lstnew(char *input, int value, int priority, char **command)
{
	t_parsing	*new;

	new = (t_parsing *)ft_memalloc(sizeof(t_parsing));
	new->input = input;
	new->command = command;
	new->env = NULL;
	new->env_option = 0;
	new->value = value;
	new->priority = priority;
	return (new);
}

void			lstadd(t_parsing *node, t_parsing *new)
{
	if (node && new)
	{
		while (node->next)
			node = node->next;
		node->next = new;
		new->prev = node;
	}
}

void			lstdel(t_parsing **node)
{
	t_parsing	*memory;

	while (*node)
	{
		memory = *node;
		*node = (*node)->next;
		ft_memdel((void **)&memory->input);
		ft_arraydel(&memory->command);
		ft_memdel((void **)&memory);
	}
}

void			ft_arraydel(char ***array)
{
	size_t		index;

	index = 0;
	while (*array && (*array)[index])
	{
		ft_memdel((void **)&(*array)[index]);
		index++;
	}
	ft_memdel((void **)array);
}

void			cmddel(t_cmd **cmd)
{
	t_cmd		*memory;

	while (*cmd)
	{
		memory = *cmd;
		*cmd = (*cmd)->next;
		ft_memdel((void **)&memory);
	}
}
