/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_value.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/02 15:59:47 by aroulin           #+#    #+#             */
/*   Updated: 2017/09/23 19:51:24 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

unsigned int		hash_value(char *str)
{
	int					i;
	unsigned short		nb;

	i = -1;
	nb = 0;
	while (str[++i])
	{
		nb += str[i];
		nb += (nb << 10);
		nb ^= (nb >> 6);
	}
	nb += (nb << 3);
	nb ^= (nb >> 11);
	nb += (nb << 15);
	nb = (nb % USHRT_MAX);
	return (nb);
}
