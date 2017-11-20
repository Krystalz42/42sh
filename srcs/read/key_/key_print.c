/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <aroulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/12 21:50:30 by aroulin           #+#    #+#             */
/*   Updated: 2017/11/16 16:15:46 by jle-quel         ###   ########.fr       */
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

int			key_print_fct(t_cmd *cmd, char c)
{
	t_cmd			*element;

	element = create_element(c);
	element->prev = cmd->prev;
	element->next = cmd;
	if (cmd->prev)
		cmd->prev->next = element;
	cmd->prev = element;
	return (1);
}

int			key_print_(t_read **read_std, unsigned long *buff)
{
	int		c;

	(*read_std)->history_search += (*read_std)->history_search ? 1 : 0;
	!(*read_std)->history_search ? add_outstanding(NULL, PRINT_KEY, *buff) : 0;
	while (*buff)
	{
		c = (*buff % (UCHAR_MAX + 1));
		*buff /= (UCHAR_MAX + 1);
		if (ft_iscrlf(c))
			return (key_enter_(read_std, c));
		else if (ft_isprint(c))
		{
			if ((*read_std)->history_search)
			{
				key_print_fct((*read_std)->hist_search->cmd, c);
				compare_history(read_std);
			}
			else
			{
				key_print_fct((*read_std)->cmd, c);
				(*read_std)->print = 2;
			}
		}
	}
	return (1);
}
