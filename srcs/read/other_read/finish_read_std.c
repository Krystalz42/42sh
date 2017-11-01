/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish_read_std.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 16:43:48 by aroulin           #+#    #+#             */
/*   Updated: 2017/10/18 21:57:36 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

static t_cmd	*copy_command(t_cmd *cmd)
{
	t_cmd		*cpy;

	cpy = create_element('\0');
	while (cmd->c)
	{
		key_print_fct(cpy, cmd->c);
		cmd = cmd->next;
	}
	return (cpy);
}

static int		empty_cmd(t_cmd *cmd)
{
	while (cmd->c)
	{
		if (cmd->c != 32)
			return (0);
		cmd = cmd->next;
	}
	return (1);
}

static t_cmd	*return_line(t_read **read_std)
{
	t_cmd		*line;

	if (*read_std)
	{
		(*read_std)->finish = 0;
		if (get_len_prompt(-42) != -2)
			make_list_hist((*read_std));
		line = copy_command(first_cmd((*read_std)->cmd, 1));
		if (get_len_prompt(-42) == -2)
			memdel_read(read_std);
		return (line);
	}
	return (NULL);
}

t_cmd			*finish_read_std(t_read **read_std)
{
	t_cmd		*tmp;

	tmp = first_cmd(gbl_save_read(NULL), 1);
	reset_history();
	memdel_outstanding();
	if ((*read_std)->history)
		memdel_cmd(&tmp);
	if (signal_reception(-1) || empty_cmd(first_cmd((*read_std)->cmd, 1)))
	{
		if (signal_reception(-1))
			insert_one_line();
		memdel_read(read_std);
	}
	return (return_line(read_std));
}
