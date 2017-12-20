/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_downcase_word.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 17:22:37 by gbourson          #+#    #+#             */
/*   Updated: 2017/11/17 17:22:51 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

int				key_downcase_word(t_read **read_std, unsigned long buff)
{
	add_outstanding(NULL, buff, 0);
	while ((*read_std)->cmd->c && ft_isalnum((*read_std)->cmd->c) == 0)
		(*read_std)->cmd = (*read_std)->cmd->next;
	while ((*read_std)->cmd->c && ft_isalnum((*read_std)->cmd->c))
	{
		if (ft_isupper((*read_std)->cmd->c))
			(*read_std)->cmd->c += 32;
		(*read_std)->cmd = (*read_std)->cmd->next;
	}
	(*read_std)->print = 2;
	return (1);
}
