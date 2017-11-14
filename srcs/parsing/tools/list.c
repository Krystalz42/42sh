/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:58:31 by jle-quel          #+#    #+#             */
/*   Updated: 2017/11/14 14:31:56 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

/*
*************** PUBLIC *********************************************************
*/

t_parsing		*lstnew(char *input)
{
	t_parsing	*new;

	new = (t_parsing *)ft_memalloc(sizeof(t_parsing));
	new->input = input;
	new->command = NULL;
	new->env = NULL;
	new->env_option = 0;
	new->value = 0;
	new->priority = 0;
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
		memory->command = NULL;
		ft_memdel((void **)&memory);
	}
}
