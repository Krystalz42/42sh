/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_enter_.c                                        :+:      :+:    :+:   */
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
	tmp = (*read_std)->tab_->file;
	while (tmp)
	{
		if (tmp->index == (*read_std)->tab_->index)
		{
			if (!ft_strcmp((*read_std)->tab_->from, tmp->name))
				(DT_DIR & tmp->type) ? (key_print_(read_std, '/')) : bip();
			else
			{
				while ((*read_std)->cmd->prev && (*read_std)->cmd->prev->c != 32
					   && (*read_std)->cmd->prev->c != '/')
					key_del(read_std);
				while (tmp->name[++i])
					key_print_(read_std, tmp->name[i]);
			}
		}
		tmp = tmp->next;
	}
	((*read_std)->completion) && ((*read_std)->completion = 0);
}

int			key_enter_(t_read **read_std)
{
	if ((*read_std)->completion)
		complete_command(read_std);
	else
	{
		if (!(check_cmd(read_std)))
			(*read_std)->finish = 1;
		else
		{
			(*read_std)->cmd = last_cmd((*read_std)->cmd);
			key_print_(read_std, 10);
			insert_one_line();
		}
	}
	return (1);
}
