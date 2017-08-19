/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 21:05:29 by aroulin           #+#    #+#             */
/*   Updated: 2017/08/19 22:36:15 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>


char			keep_this_char(char c)
{
	static char to_keep;

	if (c != -1)
		to_keep = c;
	return (to_keep);
}

t_cmd			*rec_brackets(t_cmd *cmd, char c)
{
	keep_this_char(c);
	while (cmd)
	{
		if (cmd->prev && cmd->prev->c == '\\')
		{
			cmd = cmd->next;
			continue ;
		}
		if (cmd->c == c)
			return ((c) ? cmd->next : cmd);
		if ((cmd->c == '\'' || cmd->c == '\"') && c == '\0')
		{
			if (!(cmd = rec_brackets(cmd->next, cmd->c)))
				return (NULL);
		}
		else
			cmd = cmd->next;
	}
	return (NULL);
}

int			check_cmd(t_read **read_std)
{
	t_cmd *tmp;

	if ((tmp = rec_brackets(first_cmd((*read_std)->cmd, 0), '\0'), fdb))
		;
	if (tmp)	
		(*read_std)->finish = 1;
	else if (!keep_this_char(-1))
		prompt(NEXTCMD, NULL);
	else if (keep_this_char(-1) == '\'')
		prompt(QUOTE, NULL);
	else if (keep_this_char(-1) == '\"')
		prompt(DQUOTE, NULL);
	return (1);
}
