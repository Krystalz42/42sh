/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelazou <sbelazou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 17:36:39 by sbelazou          #+#    #+#             */
/*   Updated: 2017/11/15 17:28:10 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

uint8_t				ft_echo(t_node *node, int info)
{
	(void)node;
	(void)info;
}
//
// const t_echo	g_echo[] =
// {
// 	(t_echo){"-n", OPTION_N},
// 	(t_echo){"-e", OPTION_E}
// };
//
// /*
// *************** PRIVATE ********************************************************
// */
// //
// // static uint8_t	get_option(char **argv)
// // {
// // 	short		index;
// // 	uint8_t		status;
// //
// // 	status = DEFAULT;
// // 	while (argv && *argv)
// // 	{
// // 		index = 0;
// // 		while (index < 2)
// // 		{
// // 			if (!ft_strcmp(*argv, g_echo[index].str))
// // 				status |= g_echo[index].status;
// // 			index++;
// // 		}
// // 		argv++;
// // 	}
// // 	return (status);
// }
//
// while (ft_putst )
//
//
// /*
// *************** PUBLIC *********************************************************
// */
//
// uint8_t			ft_echo(t_node *node, int info __attribute__((unused)))
// {
// 	uint8_t		options;
// 	char		**argv;
//
// 	argv = node->content->command + 1;
// 	if (argv)
// 	{
// 		options = get_option(node->content->command + 1);
// 		do_echo(node->content->command + 1);
// 	}
// 	options & OPTION_N ? ft_putchar(10) : 0;
// 	else
// 	return (0);
// }
