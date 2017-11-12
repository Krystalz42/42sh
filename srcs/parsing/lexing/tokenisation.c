/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenisation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:14:24 by jle-quel          #+#    #+#             */
/*   Updated: 2017/11/11 11:19:02 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

/*
*************** TOOLS **********************************************************
*/

static bool		chk(t_cmd *cmd, int status, size_t occurence)
{
	if (!(status & QUOTE))
	{
		if (cmd && cmd->c && cmd->c == '\\')
			return (chk(cmd->prev, status, occurence + 1));
	}
	return (occurence % 2);
}

/*
*************** PRIVATE ********************************************************
*/

static int		get_value(char c)
{
	short				index;
	static const char	*operaters = ";|<>&";

	if (c)
	{
		index = 0;
		while (operaters[index])
		{
			if (operaters[index] == c)
				return (OPERATER);
			index++;
		}
	}
	return (TOKEN);
}

static int		populate(t_cmd *cmd)
{
	if (cmd && cmd->c)
	{
		if (cmd->c == ' ')
			return (OPERATER);
		if (!ft_isdigit(cmd->c))
			return (TOKEN);
		else
			return ((cmd->value = populate(cmd->prev)));
	}
	return (OPERATER);
}

/*
*************** PUBLIC *********************************************************
*/

void			tokenisation(t_cmd *cmd)
{
	uint8_t		status;

	status = DEFAULT;
	while (cmd && cmd->c)
	{
		cmd->value = TOKEN;
		if (!chk(cmd->prev, status, 0))
		{
			if (chk_quote(cmd->c, &status) && (status & DEFAULT))
			{
				cmd->value = get_value(cmd->c);
				cmd->c == '>' ? populate(cmd->prev) : 0;
			}
		}
		cmd = cmd->next;
	}
}
