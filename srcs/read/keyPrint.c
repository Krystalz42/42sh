/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/12 21:50:30 by aroulin           #+#    #+#             */
/*   Updated: 2017/08/19 20:09:43 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

t_cmd		*create_element(char c)
{
	t_cmd *element;

	element = (t_cmd *)ft_memalloc(sizeof(t_cmd));
	element->next = NULL;
	element->prev = NULL;
	element->c = c;
	return (element);
}

int			key_print_(t_read **read_std, char c)
{
	t_cmd *element;

	element = create_element(c);
	element->prev = (*read_std)->cmd->prev;
	element->next = (*read_std)->cmd;
	if ((*read_std)->cmd->prev)
		(*read_std)->cmd->prev->next = element;
	(*read_std)->cmd->prev = element;
	return (1);
}
