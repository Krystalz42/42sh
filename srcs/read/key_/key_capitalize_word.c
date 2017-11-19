/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_capitalize_word.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 17:31:11 by gbourson          #+#    #+#             */
/*   Updated: 2017/11/17 17:32:19 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

int				capitalize_word_undo(t_read **read_std, unsigned long buff)
{
	(void)buff;
	while ((*read_std)->cmd->prev && (*read_std)->cmd->c == 32)
		(*read_std)->cmd = (*read_std)->cmd->prev;
	if ((*read_std)->cmd->prev)
		(*read_std)->cmd = (*read_std)->cmd->prev;
	while ((*read_std)->cmd->prev && (*read_std)->cmd->prev->c != 32 \
		&& ft_isalpha((*read_std)->cmd->c))
		(*read_std)->cmd = (*read_std)->cmd->prev;
	if (ft_isalpha((*read_std)->cmd->c))
		(*read_std)->cmd->c += 32;
	if ((*read_std)->cmd->prev)
		(*read_std)->cmd = (*read_std)->cmd->prev;
	return (1);
}

int				capitalize_word(t_read *read_std)
{
	while (read_std->cmd->c == 32)
		read_std->cmd = read_std->cmd->next;
	if (ft_isalpha(read_std->cmd->c) && ft_islower(read_std->cmd->c))
	{
		read_std->cmd->c -= 32;
		while (ft_isalpha(read_std->cmd->c))
			read_std->cmd = read_std->cmd->next;
		return (1);
	}
	return (0);
}

int				key_capitalize_word(t_read **read_std, unsigned long buff)
{
	if ((*read_std)->history_search)
		(*read_std)->print = 2;
	else
	{
		if (capitalize_word(*read_std))
			add_outstanding(NULL, buff, 0);
		(*read_std)->print = 2;
	}
	return (1);
}
