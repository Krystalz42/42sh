/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complete_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/13 04:23:45 by aroulin           #+#    #+#             */
/*   Updated: 2017/08/13 05:40:20 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

t_cmd		*beg_word(t_read **read_std)
{
	t_cmd 		*tmp;

	tmp = (*read_std)->cmd;
	while (tmp->prev->c != 32)
		tmp = tmp->prev;
	return (tmp);
}

int			len_word(t_cmd *cmd)
{
	int		i;

	i = 0;
	if (!cmd->c && cmd->prev && cmd->prev->c == 32)
		return (0);
	while (cmd->c != 32)
	{
		NBR(cmd->prev->c);
		i++;
		if (cmd->prev)
			cmd = cmd->prev;
	}
	NL;
	return (i);
}

void		complete_path(t_read **read_std)
{
	t_cmd		*tmp;
	int			i;

	if (!((*read_std)->comp = (t_completion *)ft_memalloc(sizeof(t_completion))))
		return ;
	(*read_std)->comp->file = NULL;
	tmp = beg_word(read_std);
	i = len_word(tmp);
	create_comp(read_std, tmp, i);
}
