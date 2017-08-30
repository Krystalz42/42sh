/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <aroulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 00:00:21 by aroulin           #+#    #+#             */
/*   Updated: 2016/01/01 00:00:42 by aroulin          ###   ########.fr       */
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

char			*ft_itoa(int n)
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
