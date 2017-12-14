/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   regular_tokenisation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelazou <sbelazou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 19:50:25 by jle-quel          #+#    #+#             */
/*   Updated: 2017/12/14 12:43:05 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

/*
*************** PRIVATE ********************************************************
*/

static int		get_value(char c)
{
	short				index;
	static const char	*operaters = ";|<>&";

	index = 0;
	while (c && operaters[index])
	{
		if (operaters[index] == c)
			return (OPERATER);
		index++;
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

void			regular_tokenisation(t_cmd *cmd)
{
	uint8_t		quote;
	uint8_t		temp;

	quote = DEFAULT;
	temp = quote;
	while (cmd && cmd->c)
	{
		cmd->value = TOKEN;
		if (cmd->status == DEFAULT)
		{
			cmd->value = get_value(cmd->c);
			cmd->c == '>' || cmd->c == '<' ? populate(cmd->prev) : 0;
		}
		cmd = cmd->next;
	}
}
