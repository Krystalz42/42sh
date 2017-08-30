/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkCmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 21:05:29 by aroulin           #+#    #+#             */
/*   Updated: 2017/08/30 21:02:47 by aroulin          ###   ########.fr       */
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
	while (cmd)
	{
		if (cmd->prev && cmd->prev->c == '\\')
		{
			cmd = cmd->next;
			keep_this_char('\\');
			continue ;
		}
		keep_this_char(c);
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

int			checkCmd(t_read **readStd)
{
	t_cmd *tmp;

	if ((tmp = rec_brackets(firstCmd((*readStd)->cmd, 1), '\0'), fdb))
		;
	if (tmp)	
		return ((*readStd)->finish = 1);
	keyPrint(readStd, 10);
	insertOneLine();
	restoreCursor((*readStd)->cur);
	keyEnd(readStd);
	printList(1, firstCmd((*readStd)->cmd, 0), (*readStd)->cmd, (*readStd));
	if (keep_this_char(-1) == '\\')
		prompt(NEXTCMD, NULL);
	else if (keep_this_char(-1) == '\'')
		prompt(QUOTE, NULL);
	else if (keep_this_char(-1) == '\"')
		prompt(DQUOTE, NULL);
	return (1);
}
