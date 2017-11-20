/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_enter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 17:16:59 by gbourson          #+#    #+#             */
/*   Updated: 2017/11/19 11:54:12 by sbelazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

void		insert_completion(t_read **read_std, t_file *tmp)
{
	int		i;

	i = -1;
	(*read_std)->completion = 0;
	if (!ft_strcmp((*read_std)->tab_->from, tmp->name)\
		&& (DT_DIR & tmp->type))
		key_print_fct((*read_std)->cmd, '/');
	else
	{
		while ((*read_std)->cmd->prev && (*read_std)->cmd->prev->c != 32
				&& (*read_std)->cmd->prev->c != '/')
			key_del_fct((*read_std)->cmd, 0);
		while (tmp->name[++i])
			key_print_fct((*read_std)->cmd, tmp->name[i]);
	}
	(*read_std)->print = 2;
}

void		complete_command(t_read **read_std)
{
	t_file	*tmp;

	tmp = (*read_std)->tab_->file;
	while (tmp)
	{
		if (tmp->index == (*read_std)->tab_->index)
			insert_completion(read_std, tmp);
		tmp = tmp->next;
	}
}

int			key_enter_(t_read **read_std, unsigned long buff)
{
	buff++;
	if ((*read_std)->completion)
		complete_command(read_std);
	else
	{
		(*read_std)->cmd = last_cmd((*read_std)->cmd);
		(*read_std)->print = 2;
		print_struct(*read_std);
		insert_one_line();
		if (!(check_cmd(read_std)))
			(*read_std)->finish = 1;
		else
		{
			(*read_std)->print = 2;
			(*read_std)->cur.line = 1;
			key_print_fct((*read_std)->cmd, buff);
			(*read_std)->history = 0;
		}
	}
	return (1);
}
