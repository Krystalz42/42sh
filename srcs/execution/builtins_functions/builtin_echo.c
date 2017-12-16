/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelazou <sbelazou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 17:36:39 by sbelazou          #+#    #+#             */
/*   Updated: 2017/11/17 16:51:30 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

/*
*************** PRIVATE ********************************************************
*/

static char		**get_argv(char **argv, uint8_t *option)
{
	size_t		index;

	index = 0;
	while (argv && argv[index])
	{
		if (!ft_strcmp(argv[index], "-n"))
			*option = OPTION_N;
		else
			break ;
		index++;
	}
	return (argv + index);
}

static void		print_argv(char **argv)
{
	size_t		index;

	index = 0;
	while (argv && argv[index])
	{
		ft_putstr(argv[index]);
		argv[index + 1] ? ft_putchar('\040') : 0;
		index++;
	}
}

/*
*************** PUBLIC *********************************************************
*/

uint8_t			builtin_echo(t_parsing *node, int info)
{
	uint8_t		option;
	char		**argv;

	(void)info;
	option = DEFAULT;
	argv = get_argv(node->command + 1, &option);
	print_argv(argv);
	option & DEFAULT || !argv ? ft_putchar('\012') : 0;
	return (0);
}
