/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_tokenisation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 19:39:01 by jle-quel          #+#    #+#             */
/*   Updated: 2017/11/12 19:49:29 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

/*
*************** PRIVATE ********************************************************
*/


void		populate_backslash(t_cmd **cmd)
{
	uint8_t		index;

	index = 2;
	while (*cmd && (*cmd)->c && index--)
	{
		(*cmd)->status = BACKSLASH;
		*cmd = (*cmd)->next;
	}
}

void			populate_single_quote(t_cmd **cmd)
{
	uint8_t		occurence;

	occurence = 0;
	while (*cmd && (*cmd)->c && occurence < 2)
	{
		occurence += (*cmd)->c == '\'' ? 1 : 0;
		(*cmd)->status = SINGLE_QUOTE;
		*cmd = (*cmd)->next;
	}
}

void			populate_double_quote(t_cmd **cmd)
{
	uint8_t		occurence;

	occurence = 0;
	while (*cmd && (*cmd)->c && occurence < 2)
	{
		if ((*cmd)->c == '\\')
			populate_backslash(cmd);
		else
		{
			occurence += (*cmd)->c == '\"' ? 1 : 0;
			(*cmd)->status = DOUBLE_QUOTE;
			*cmd = (*cmd)->next;
		}
	}
}

/*
*************** PUBLIC *********************************************************
*/

void			special_tokenisation(t_cmd *cmd)
{
	while (cmd && cmd->c)
	{
		if (cmd->c == '\\')
			populate_backslash(&cmd);
		else if (cmd->c == '\'')
			populate_single_quote(&cmd);
		else if (cmd->c == '\"')
			populate_double_quote(&cmd);
		else
		{
			cmd->status = NORMAL;
			cmd = cmd->next;
		}
	}
}
