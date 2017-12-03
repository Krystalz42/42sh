/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 23:41:11 by jle-quel          #+#    #+#             */
/*   Updated: 2017/12/02 12:00:16 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>


/*
*************** PUBLIC *********************************************************
*/

size_t			arraylen(char **argv)
{
	size_t		index;

	index = 0;
	while (argv && argv[index])
		index++;
	return (index);
}

void			arraydel(char ***address)
{
	size_t		index;

	if (*address)
	{
		index = 0;
		while ((*address)[index])
		{
			ft_memdel((void **)&(*address)[index]);
			index++;
		}
		ft_memdel((void **)address);
	}
}
