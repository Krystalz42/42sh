/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelazou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 17:36:39 by sbelazou          #+#    #+#             */
/*   Updated: 2017/10/30 17:48:33 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

uint8_t				builtin_echo(t_node *node, int info __attribute__((unused)))
{
	int option;
	int table;

	table = 1;
	option = 0;
	if (node->content->command)
	while (node->content->command[table])
	{
		if (node->content->command[table][0] == '-')
			;
		else
		{
			ft_putstr(node->content->command[table]);
			if (node->content->command[table + 1])
				ft_putchar('\x20');
		}
		table++;
	}
	if (option & N)
		ft_putchar('\x0A');
	return (var_return(0));
}
