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

t_cmd		*createElement(char c)
{
	t_cmd *element;

	element = (t_cmd *)ft_memalloc(sizeof(t_cmd));
	element->next = NULL;
	element->prev = NULL;
	element->c = c;
	return (element);
}

int			keyPrint(t_read **readStd, char c)
{
	t_cmd *element;

	element = createElement(c);
	element->prev = (*readStd)->cmd->prev;
	element->next = (*readStd)->cmd;
	if ((*readStd)->cmd->prev)
		(*readStd)->cmd->prev->next = element;
	(*readStd)->cmd->prev = element;
	return (1);
}
