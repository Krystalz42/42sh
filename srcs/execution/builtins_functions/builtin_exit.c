/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <aroulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 15:22:05 by aroulin           #+#    #+#             */
/*   Updated: 2017/11/17 16:31:33 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

/*
*************** PRIVATE ********************************************************
*/

static size_t	get_len(char **argv, size_t length)
{
	return ((argv && argv[length]) ? get_len(argv, length + 1) : length);
}

/*
*************** PUBLIC *********************************************************
*/

uint8_t			builtin_exit(t_parsing *node, int info)
{
	size_t		length;
	int			var;

	(void)info;
	if ((length = get_len(node->command, 0)) == 2)
	{
		if (ft_strisdigit(node->command[1]))
			var = ft_atoi(node->command[1]);
		else
		{
			error_msg(EXIT, NUM_REQUIRED, node->command[1]);
			var = 255;
		}
		b_write_history_in_file(get_str_from_history());
		exit(var);
	}
	else if (length > 2)
		return (error_msg(EXIT, TOO_MANY_ARGS, NULL));
	else
		exit_();
	return (0);
}
