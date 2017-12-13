/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_hash.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <aroulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 15:22:12 by aroulin           #+#    #+#             */
/*   Updated: 2017/12/13 18:00:53 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

static uint8_t	get_options(char **argv)
{
	uint8_t		options;

	options = 0;
	while (*argv)
	{
		options += ft_strcmp(*argv, "-r") == 0 ? 0 : ERR;
		argv++;
	}
	return (options & ERR ? usage_hash() + 1 : hash_reset());
}

uint8_t			builtin_hash(t_node *node, int info)
{
	(void)info;
	if (arraylen(node->content->command) == 1)
		return (hash_print(STDOUT_FILENO));
	if (ft_strcmp(node->content->command[1], HELP) == 0)
		return (usage_hash());
	return (get_options(node->content->command + 1));
}
