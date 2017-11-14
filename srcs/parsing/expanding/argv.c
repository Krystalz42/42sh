/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 12:00:55 by jle-quel          #+#    #+#             */
/*   Updated: 2017/11/14 14:30:14 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

const t_argv	g_argv[] =
{
	(t_argv){";"},
	(t_argv){"&&"},
	(t_argv){"||"},
	(t_argv){"|"},
	(t_argv){"&"},
	(t_argv){"<<"},
	(t_argv){">>"},
	(t_argv){">&"},
	(t_argv){"&>"},
	(t_argv){"<"},
	(t_argv){">"}
};

char		**ft_arraysub(char **argv, size_t start, size_t length)
{
	size_t		index;
	char		**new;

	new = NULL;
	if (argv && length > 0)
	{
		index = 0;
		new = (char **)ft_memalloc(sizeof(char *) * (length + 1));
		while (length--)
			new[index++] = ft_strdup(argv[start++]);
	}
	return (new);
}

size_t			ft_arraylen(char **argv)
{
	size_t		index;

	index = 0;
	while (argv[index])
		index++;
	return (index);
}

char			**ft_arrayjoin(char **a1, char **a2)
{
	size_t		index;
	size_t		i;
	char		**new;

	new = NULL;
	if (!a1 && a2)
		return (ft_arraysub(a2, 0, ft_arraylen(a2)));
	if (!a2 && a1)
		return (ft_arraysub(a1, 0, ft_arraylen(a1)));
	if (!a1 && !a2)
		return (NULL);
	index = 0;
	i = 0;
	new = (char**)ft_memalloc(sizeof(char*) * (ft_arraylen(a1) + ft_arraylen(a2) + 1));
	while (a1[i])
		new[index++] = ft_strdup(a1[i++]);
	i = 0;
	while (a2[i])
		new[index++] = ft_strdup(a2[i++]);
	new[index] = NULL;
	return (new);
}


/*
*************** TOOLS **********************************************************
*/

static void		ptr_next(t_parsing **node)
{
	while (*node && (*node)->next)
		*node = (*node)->next;
}

static bool		chk(t_parsing *node, int start, int length)
{
	if (node && node->command && node->command[0])
	{
		while (start++ < length)
		{
			if (ft_strstr(node->command[0], g_argv[start].str))
				return (true);
		}
	}
	return (false);
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
		if (chk(node->prev, 5, 10))
		{
			if (ft_arraylen(node->command) > 1)
			{
				memory = temp;
				temp = ft_arrayjoin(get_argv(node->command), temp);
				ft_memdel_tab(&memory);
				remove_argv(&node->command);
			}
		}
		if (chk(node->prev, 0, 4) || !node->prev)
		{
			memory = node->command;
			node->command = ft_arrayjoin(node->command, temp);
			ft_memdel_tab(&memory);
		}
		node = node->prev;
	}
}
