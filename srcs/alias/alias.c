/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alias.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 23:34:22 by jle-quel          #+#    #+#             */
/*   Updated: 2017/12/13 15:51:43 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

/*
*************** PRIVATE ********************************************************
*/

static t_alias	*create_alias(char **argv)
{
	t_alias		*new;

	new = (t_alias *)ft_memalloc(sizeof(t_alias));
	new->variable = ft_strtrim(argv[0]);
	new->value = ft_strtrim(argv[1]);
	new->times = 0;
	new->next = NULL;
	return (new);
}

/*
*************** PUBLIC *********************************************************
*/

t_alias			**get_alias(void)
{
	static t_alias	*alias_board[USHRT_MAX];

	return (alias_board);
}

char			*alias_exist(char *str)
{
	size_t		index;
	t_alias		**ptr;
	t_alias		*temp;

	index = hash_value(str);
	ptr = get_alias();
	if ((temp = ptr[index]))
	{
		while (temp)
		{
			if (!ft_strcmp(temp->variable, str))
			{
				temp->times += 1;
				return (temp->value);
			}
			temp = temp->next;
		}
	}
	return (NULL);
}

void			add_alias(char **argv)
{
	size_t		index;
	t_alias		**ptr;
	t_alias		*temp;

	index = hash_value(argv[0]);
	ptr = get_alias();
	if ((temp = ptr[index]))
	{
		while (temp->next)
			temp = temp->next;
		temp->next = create_alias(argv);
	}
	else
		ptr[index] = create_alias(argv);
}
