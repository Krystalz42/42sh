/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 12:00:55 by jle-quel          #+#    #+#             */
/*   Updated: 2017/11/14 16:26:51 by jle-quel         ###   ########.fr       */
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

static char		**get_argv(char **argv)
{
	char		**dup;

	dup = ft_arraysub(argv, 1, ft_arraylen(argv));
	return (dup);
}

static void		remove_argv(char ***argv)
{
	char		**new;

	new = ft_arraysub(*argv, 0, 1);
	ft_memdel_tab(argv);
	*argv = new;
}

/*
*************** PUBLIC *********************************************************
*/

void			argv(t_parsing *node)
{
	char		**temp;
	char		**memory;

	temp = NULL;
	ptr_next(&node);
	while (node)
	{
		if (chk_get_argv(node->prev))
		{
			if (ft_arraylen(node->command) > 1)
			{
				memory = temp;
				temp = ft_arrayjoin(get_argv(node->command), temp);
				ft_memdel_tab(&memory);
				remove_argv(&node->command);
			}
		}
		else if (chk_add_argv(node->prev) || !node->prev)
		{
			memory = node->command;
			node->command = ft_arrayjoin(node->command, temp);
			ft_memdel_tab(&memory);
			ft_memdel_tab(&temp);
		}
		node = node->prev;
	}
}
