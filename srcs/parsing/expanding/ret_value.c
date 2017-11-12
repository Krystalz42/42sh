/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ret_value.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 17:05:38 by jle-quel          #+#    #+#             */
/*   Updated: 2017/11/10 17:46:20 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

/*
*************** PRIVATE ********************************************************
*/

static bool		expansion(char **str, size_t index)
{
	if (!ft_strncmp(*str + index, "$?", 2))
	{
		return (true);
	}
	return (false);
}


/*
*************** PUBLIC *********************************************************
*/

void			ret_value(t_parsing *node)
{
	size_t		index;
	uint8_t		status;
	t_parsing	*temp;
	
	status = DEFAULT;
	temp = node;
	while (node)
	{
		index = 0;
		while (node->input && node->input[index])
		{
			chk_quote(node->input[index], &status);
			if (status & (DEFAULT | DQUOTE) && expansion(&node->input, index))
				;
			index++;
		}
		node = node->next;
	}
}
