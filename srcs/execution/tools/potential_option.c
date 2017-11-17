/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   potential_option.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 15:11:42 by jle-quel          #+#    #+#             */
/*   Updated: 2017/11/17 15:11:57 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

int		potential_option(char *potential, int c)
{
	int						index;

	index = 0;
	while (potential[index])
	{
		if (potential[index] == c)
			return (1);
		index++;
	}
	return (0);
}
