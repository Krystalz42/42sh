/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:47:53 by jle-quel          #+#    #+#             */
/*   Updated: 2017/11/09 15:48:05 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

/*
*************** PUBLIC *********************************************************
*/

uint8_t			chk_quote(char c, uint8_t *status)
{
	if (c)
	{
		if (c == '\'' && !(*status & DQUOTE))
			*status = *status & QUOTE ? DEFAULT : QUOTE;
		else if (c == '\"' && !(*status & QUOTE))
			*status = *status & DQUOTE ? DEFAULT : DQUOTE;
	}
	return (*status);
}
