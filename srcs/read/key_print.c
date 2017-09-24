/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_print_.c                                        :+:      :+:    :+:   */
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

int			key_print_fct(t_cmd *cmd, char c)
{
	t_cmd *element;

	element = create_element(c);
	element->prev = cmd->prev;
	element->next = cmd;
	if (cmd->prev)
		cmd->prev->next = element;
	cmd->prev = element;
	return (1);
}

int			key_print_(t_read **read_std, char c)
{
    if ((*read_std)->history_search)
    {
        key_print_fct((*read_std)->hist_search->cmd, c);
        compare_history(read_std);
        (*read_std)->history_search++;
    }
    else
    {
	    (*read_std)->print = 2;
	    key_print_fct((*read_std)->cmd, c);
    }
	return (1);
}
