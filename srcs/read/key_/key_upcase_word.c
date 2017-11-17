/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_upcase_word.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 16:46:42 by gbourson          #+#    #+#             */
/*   Updated: 2017/11/17 16:46:54 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

int				key_upcase_word(t_read **read_std, unsigned long buff)
{
	(*read_std)->cmd = (*read_std)->cmd;
	add_outstanding(NULL, buff, 0);
	while ((*read_std)->cmd->c && (*read_std)->cmd->c == 32)
		(*read_std)->cmd = (*read_std)->cmd->next;
	while ((*read_std)->cmd->c && ft_isalnum((*read_std)->cmd->c))
	{
		if (ft_islower((*read_std)->cmd->c))
			(*read_std)->cmd->c -= 32;
		(*read_std)->cmd = (*read_std)->cmd->next;
	}
	(*read_std)->print = 2;
	return (1);
}
