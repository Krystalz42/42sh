/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 12:00:55 by jle-quel          #+#    #+#             */
/*   Updated: 2017/11/14 14:55:34 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "sh.h"
//
// const t_argv	g_argv[] =
// {
// 	(t_argv){";"},
// 	(t_argv){"&&"},
// 	(t_argv){"||"},
// 	(t_argv){"|"},
// 	(t_argv){"&"},
// };
//
// /*
// *************** TOOLS **********************************************************
// */
//
// static void		ptr_next(t_parsing **node)
// {
// 	while (*node && (*node)->next)
// 		*node = (*node)->next;
// }
//
// static bool		chk(t_parsing *node)
// {
// 	short		index;
//
// 	if (node && node->command && node->command[0] && node->value)
// 	{
// 		index = 0;
// 		while (index < 5)
// 		{
// 			ft_putendl(g_argv[index].str);
// 			index++;
// 			// if (ft_strcmp(node->command[0], g_argv[index].str))
// 				// return (true);
// 		}
// 	}
// 	return (false);
// }
//
// /*
// *************** PRIVATE ********************************************************
// */
//
// // static char		**get_argv(char **argv)
// // {
// // 	char		**dup;
// //
// // 	dup = ft_arraysub(argv, 1, ft_arraylen(argv));
// // 	return (dup);
// // }
// //
// // static void		remove_argv(char ***argv)
// // {
// // 	char		**new;
// //
// // 	new = ft_arraysub(*argv, 0, 1);
// // 	ft_memdel_tab(argv);
// // 	*argv = new;
// // }
//
// /*
// *************** PUBLIC *********************************************************
// */
//
// void			argv(t_parsing *node)
// {
// 	char		**temp;
// 	// char		**memory;
//
// 	temp = NULL;
// 	ptr_next(&node);
// 	while (node)
// 	{
// 		if (chk(node->prev))
// 			ft_putendl("OUI");
// 	// 	{
// 	// 		if (ft_arraylen(node->command) > 1)
// 	// 		{
// 	// 			memory = temp;
// 	// 			temp = ft_arrayjoin(get_argv(node->command), temp);
// 	// 			ft_memdel_tab(&memory);
// 	// 			remove_argv(&node->command);
// 	// 		}
// 	// 	}
// 	// 	if (chk(node->prev, 0, 4) || !node->prev)
// 	// 	{
// 	// 		memory = node->command;
// 	// 		node->command = ft_arrayjoin(node->command, temp);
// 	// 		ft_memdel_tab(&memory);
// 	// 	}
// 		node = node->prev;
// 	}
// }
