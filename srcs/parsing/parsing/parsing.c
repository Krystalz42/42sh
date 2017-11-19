/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 20:34:39 by jle-quel          #+#    #+#             */
/*   Updated: 2017/11/19 03:53:28 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

/*
*************** PRIVATE ********************************************************
*/

static void		err(char *str, int err, t_parsing **node)
{
	ft_err(str, err);
	lstdel(node);
	var_return(1);
}

static bool		isonly(char *str, char c)
{
	while (*(str))
	{
		if (*(str) != c)
			return (false);
		str++;
	}
	return (true);
}

/*
*************** PUBLIC *********************************************************
*/

void			order(t_parsing **node)
{
	uint8_t		rounds;
	t_parsing	*temp;

	if (*node)
	{
		rounds = 0;
		temp = *node;
		while (temp->next)
		{
			if (rounds == 0 && temp->value)
			{
				err(temp->input, SYNTAX_ERR, node);
				return ;
			}
			rounds = rounds ? 0 : 1;
			temp = temp->next;
		}
		if (temp->value && temp->value != 2)
			err(temp->input, SYNTAX_ERR, node);
	}
}

void			syntax(t_parsing **node)
{
	t_parsing	*temp;

	temp = *node;
	while (temp)
	{
		if (temp->value == SYNTAX_ERR)
		{
			err(temp->input, SYNTAX_ERR, node);
			return ;
		}
		temp = temp->next;
	}
}

void			empty(t_parsing **node)
{
	size_t		index;
	t_parsing	*temp;

	index = 0;
	temp = *node;
	while (temp)
	{
		if (isonly(temp->input, ' '))
		{
			index ? err(" ", SYNTAX_ERR, node) : lstdel(node);
			return ;
		}
		index++;
		temp = temp->next;
	}
}
