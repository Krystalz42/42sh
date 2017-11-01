/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 15:22:05 by aroulin           #+#    #+#             */
/*   Updated: 2017/10/30 15:22:06 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

uint8_t				builtin_exit(t_node *node, int info)
{
	int var;

	(void)info;
	if (node->content->command[1] && node->content->command[2] == NULL)
	{
		if (ft_strisdigit(node->content->command[1]))
			var = ft_atoi(node->content->command[1]);
		else
		{
			error_builtin(EXIT, NUM_REQUIRED, node->content->command[1]);
			var = 255;
		}
		b_write_history_in_file(get_str_from_history());
		ft_putendl("exit");
		exit(var);
	}
	else if (node->content->command[2])
		return (error_builtin(EXIT, TOO_MANY_ARGS, NULL));
	else
		exit_();
	return (0);
}