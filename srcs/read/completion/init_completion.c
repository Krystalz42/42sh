/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_completion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/13 03:59:11 by aroulin           #+#    #+#             */
/*   Updated: 2017/08/19 14:05:31 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

int			is_token(char c)
{
	const char		*token;
	int				i;

	token = "|;&";
	i = 0;
	while (++i < 3)
		if (token[i] == c)
			return (1);
	return (0);
}

int			check_word(t_cmd *cmd)
{
	while (cmd->prev)
	{
		if (is_token(cmd->prev->c))
			return (1);
		if (cmd->prev->c != 32 && cmd->prev->c != 9)
			return (0);
	}
	return (0);
}

int			empty_cmd(t_cmd *cmd)
{
	if (!cmd->prev)
		return (1);
	while (cmd->prev)
	{
		cmd = cmd->prev;
		if (cmd->c != 32 && cmd->c != 0 && cmd->c != 9)
			return (0);
	}
	return (1);
}

void		init_completion(t_read **read_std)
{
	if (empty_cmd((*read_std)->cmd))
		key_print_(read_std, 9);
	else if (check_word((*read_std)->cmd))
	{
		(*read_std)->completion = 2;
		complete_binary(read_std);

	}
	else
	{
		(*read_std)->completion = 2;
		completion(read_std);
	}
}
