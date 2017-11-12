/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:47:53 by jle-quel          #+#    #+#             */
/*   Updated: 2017/11/12 20:39:53 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

/*
*************** PUBLIC *********************************************************
*/

size_t			skip_to_occurence(char *str, char c)
{
	size_t		index;
	uint8_t		occurence;

	index = 0;
	occurence = 0;

	while (str && str[index] && occurence < 2)
	{
		occurence += str[index] == c ? 1 : 0;
		index++;
	}
	return (index);
}
