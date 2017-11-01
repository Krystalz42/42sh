/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_hash.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 15:22:12 by aroulin           #+#    #+#             */
/*   Updated: 2017/10/30 15:22:14 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

/*
**			default print hash table
**	-r	:	reset hash table
*/

uint8_t			builtin_hash(t_node *node, int info)
{
	int		index;
	int		option;
	int		c;

	(void)info;
	option = 0;
	index = 0;
	if (node->content->command[1])
		if (ft_strcmp(node->content->command[1], HELP) == 0)
			return (usage_hash());
	while (node->content->command[++index] && (node->content->command[index][0]) == '-' && (c = -1))
		while (node->content->command[index][++c])
			if (node->content->command[index][c] == 'r')
				option = 1;
	return (option ? hash_reset() : hash_print(STDOUT_FILENO));
}
