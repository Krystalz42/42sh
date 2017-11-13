/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   regular_tokenisation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 19:50:25 by jle-quel          #+#    #+#             */
/*   Updated: 2017/11/13 19:16:33 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

/*
*************** PRIVATE ********************************************************
*/

int		get_value(char c)
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

int		populate(t_cmd *cmd)
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
			cmd->c == '>' ? populate(cmd->prev) : 0;
		}
		cmd = cmd->next;
	}
}
