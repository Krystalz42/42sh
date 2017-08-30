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

void		complete_command(t_read **read_std)
{
	t_file	*tmp;
	int		i;

	i = -1;
	tmp = (*read_std)->comp->tab_->file;
	while (tmp)
	{
		if (tmp->index == (*read_std)->comp->tab_->index)
		{
			if (!ft_strcmp((*read_std)->comp->from, tmp->name))
				(DT_DIR & tmp->type) ? (key_print_(read_std, '/')) : bip();
			else
			{
				while ((*read_std)->cmd->prev && (*read_std)->cmd->prev->c != 32 && (*read_std)->cmd->prev->c != '/')
					del_key(read_std);
				while (tmp->name[++i])
					key_print_(read_std, tmp->name[i]);
			}
		}
		tmp = tmp->next;
	}
	((*read_std)->completion) && ((*read_std)->completion--);
}

int			key_enter_(t_read **read_std)
{
	if ((*read_std)->completion)
	{
		complete_command(read_std);
	}
	else
	{
		check_cmd(read_std);
	}
	return (1);
}
