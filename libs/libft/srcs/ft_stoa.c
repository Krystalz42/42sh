/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 20:21:54 by jgraille          #+#    #+#             */
/*   Updated: 2017/01/04 20:41:27 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char		*format(long nbr, long *grand)
{
	size_t	len;

	len = nbr >= 0 ? 1 : 2;
	nbr = nbr >= 0 ? nbr : -nbr;
	*grand = 10;
	while (*grand <= nbr)
	{
		*grand *= 10;
		len++;
	}
	return (ft_strnew(len));
}

char			*ft_stoa(short n)
{
	long	n2;
	int		is_neg;
	char	*nbr;
	long	grand;
	size_t	len;

	n2 = n;
	nbr = format(n2, &grand);
	if (nbr == NULL)
		return (NULL);
	is_neg = n2 < 0 ? 1 : 0;
	n2 *= n2 > 0 ? 1 : -1;
	len = 0;
	while (grand > 1)
	{
		grand = grand / 10 == 0 ? 1 : grand / 10;
		nbr[is_neg + len++] = '0' + (n2 / grand);
		n2 = n2 % grand;
	}
	nbr[0] = is_neg ? '-' : nbr[0];
	return (nbr);
}
