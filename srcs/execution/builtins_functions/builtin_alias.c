/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_alias.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 15:57:47 by jle-quel          #+#    #+#             */
/*   Updated: 2017/12/01 17:55:30 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

/*
*************** PUBLIC *********************************************************
*/

uint8_t			builtin_alias(t_node *node, int info __attribute__((unused)))
{
	return (check_options_alias(node->content->command));
}

uint8_t			print_alias(void)
{
	size_t		index;
	t_alias		**ptr;
	t_alias		*temp;

	index = 0;
	ptr = get_alias();
	while (index < USHRT_MAX)
	{
		temp = ptr[index];
		while (temp)
		{
			NBR_FD(temp->times, STDOUT_FILENO);
			CHAR_FD(':', STDOUT_FILENO);
			STR_FD(temp->variable, STDOUT_FILENO);
			CHAR_FD('=', STDOUT_FILENO);
			STR_FD(temp->value, STDOUT_FILENO);
			CHAR_FD('\n', STDOUT_FILENO);
			temp = temp->next;
		}
		index++;
	}
	return (0);
}

uint8_t			remove_alias(void)
{
	size_t		index;
	t_alias		**ptr;
	t_alias		*temp;
	t_alias		*memory;

	index = 0;
	ptr = get_alias();
	while (index < USHRT_MAX)
	{
		temp = ptr[index];
		while (temp)
		{
			memory = temp;
			temp = temp->next;
			ft_memdel((void **)&(memory->variable));
			ft_memdel((void **)&(memory->value));
			ft_memdel((void **)&(memory));
		}
		ptr[index] = NULL;
		index++;
	}
	return (0);
}
