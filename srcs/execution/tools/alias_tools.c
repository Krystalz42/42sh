/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alias_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 16:57:04 by jle-quel          #+#    #+#             */
/*   Updated: 2017/12/01 18:48:41 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

/*
*************** PUBLIC *********************************************************
*/

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

uint8_t			create_alias(char **command)
{
	(void)command;
	exit(1);
	return (0);
}
