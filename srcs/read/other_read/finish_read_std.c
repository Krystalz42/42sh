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

	line = NULL;
	if (*read_std)
	{
		(*read_std)->finish = 0;
		if (get_len_prompt(-42) != KEEP && empty_cmd((*read_std)->cmd) == 0)
			make_list_hist((*read_std));
		if (get_len_prompt(-42) == KEEP || empty_cmd((*read_std)->cmd) == 0)
			line = copy_command((*read_std)->cmd);
		if (get_len_prompt(-42) == KEEP || empty_cmd((*read_std)->cmd))
			memdel_read(read_std);
		return (first_cmd(line, 1));
	}
	return (NULL);
}

t_cmd			*finish_read_std(t_read **read_std)
{
	t_cmd		*temp;

	temp = first_cmd(gbl_save_read(NULL), 1);
	(*read_std)->cmd = first_cmd((*read_std)->cmd, 1);
	reset_history();
	memdel_outstanding();
	if (temp != (*read_std)->cmd)
		memdel_cmd(&temp);
	if (signal_reception(-1))
	{
		insert_one_line();
		memdel_read(read_std);
	}
	return (return_line(read_std));
}
