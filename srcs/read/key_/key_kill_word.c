/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_kill_word.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 19:05:29 by aroulin           #+#    #+#             */
/*   Updated: 2017/09/25 19:05:30 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

int     key_kill_word(t_read **read_std, unsigned long buff)
{
	t_cmd   *kill;
	t_cmd   *tmp;

	kill = (*read_std)->cmd;
	tmp = (*read_std)->cmd;
	if (!tmp->c && bip())
		return (0);
	while (tmp->next->c == 32)
		tmp = tmp->next;
	while (ft_isalnum(tmp->next->c))
		tmp = tmp->next;
	if ((*read_std)->cmd->prev)
		(*read_std)->cmd->prev->next = tmp->next;
	tmp->next->prev = (*read_std)->cmd->prev;
	(*read_std)->cmd = tmp->next;
	(*read_std)->print = 2;
	kill->prev = NULL;
	tmp->next = NULL;
	add_outstanding(kill, buff, 0);
	return (1);
}