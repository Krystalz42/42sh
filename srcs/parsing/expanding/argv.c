/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 12:00:55 by jle-quel          #+#    #+#             */
/*   Updated: 2017/11/15 13:49:49 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

/*
*************** TOOLS **********************************************************
*/

static void		ptr_next(t_parsing **node)
{
	while (*node && (*node)->next)
		*node = (*node)->next;
}

/*
*************** PRIVATE ********************************************************
*/

static void		get_argv(char **node, char ***stack)
{
	char		**dup;
	char		**memory;

	dup = ft_arraysub(node, 1, ft_arraylen(node));
	memory = *stack;
	*stack = ft_arrayjoin(dup, *stack);
	ft_memdel_tab(&memory);
	ft_memdel_tab(&dup);
}

static void		remove_argv(char ***node)
{
	char		**new;

	new = ft_arraysub(*node, 0, 1);
	ft_memdel_tab(node);
	*node = new;
}

static void		add_argv(char ***node, char ***stack)
{
	char		**memory;

	memory = *node;
	*node = ft_arrayjoin(*node, *stack);
	ft_memdel_tab(&memory);
	ft_memdel_tab(stack);
}

/*
*************** PUBLIC *********************************************************
*/

void			argv(t_parsing *node)
{
	char		**stack;

	stack = NULL;
	ptr_next(&node);
	while (node)
	{
		if ((ft_arraylen(node->command) > 1) && chk_get_argv(node->prev))
		{
			get_argv(node->command, &stack);
			remove_argv(&node->command);
		}
		else if (chk_add_argv(node->prev) || !node->prev)
			add_argv(&node->command, &stack);
		node = node->prev;
	}
}
