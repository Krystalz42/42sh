/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_enter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/12 17:41:21 by aroulin           #+#    #+#             */
/*   Updated: 2017/08/30 20:40:30 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

void		complete_command(t_read **readStd)
{
	t_file	*tmp;
	int		i;

	i = -1;
	tmp = (*readStd)->comp->tab_->file;
	while (tmp)
	{
		if (tmp->index == (*readStd)->comp->tab_->index)
		{
			if (!ft_strcmp((*readStd)->comp->from, tmp->name))
				(DT_DIR & tmp->type) ? (keyPrint(readStd, '/')) : bip();
			else
			{
				while ((*readStd)->cmd->prev && (*readStd)->cmd->prev->c != 32 && (*readStd)->cmd->prev->c != '/')
					keyDel(readStd);
				while (tmp->name[++i])
					keyPrint(readStd, tmp->name[i]);
			}
		}
		tmp = tmp->next;
	}
	((*readStd)->completion) && ((*readStd)->completion--);
}

int			keyEnter(t_read **readStd)
{
	if ((*readStd)->completion)
	{
		complete_command(readStd);
	}
	else
	{
		checkCmd(readStd);
	}
	return (1);
}
