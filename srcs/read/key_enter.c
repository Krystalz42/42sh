/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_enter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/12 17:41:21 by aroulin           #+#    #+#             */
/*   Updated: 2017/08/17 22:39:20 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

void		complete_command(t_read **read_std)
{
	t_file	*tmp;
	char	*to_add;
	int		i;

	i = -1;
	tmp = (*read_std)->comp->tab_->file;
	while (tmp)
	{
		if (tmp->index == (*read_std)->comp->tab_->index)
		{
			if (ft_strlen(tmp->name) == ft_strlen((*read_std)->comp->from))
			{
				key_print_(read_std, '/');
				(*read_std)->completion--;
			}
			to_add = tmp->name + ft_strlen((*read_std)->comp->from);
			while (to_add && to_add[++i])
				key_print_(read_std, to_add[i]);
		}
		tmp = tmp->next;
	}
}

int			key_enter_(t_read **read_std)
{
	if ((*read_std)->completion)
	{
		complete_command(read_std);
	}
	else
		;
	return (1);
}
