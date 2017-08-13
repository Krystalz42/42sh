/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_completion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/13 03:59:11 by aroulin           #+#    #+#             */
/*   Updated: 2017/08/13 04:55:27 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

int			first_word(t_read **read_std)
{
	t_cmd		*tmp;

	tmp = (*read_std)->cmd;
	while (tmp->prev)
	{
		if (tmp->c == 32)
			return (0);
		tmp = tmp->prev;
	}
	return (1);
}

void		init_completion(t_read **read_std)
{
	if (!(*read_std)->cmd->prev && !(*read_std)->cmd->c)
		key_print_(read_std, 9);
	else if (first_word(read_std))
		complete_binary(read_std);
	else
	{
		STR("PATH\n");
		complete_path(read_std);
	}
}
