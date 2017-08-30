/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ustoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <aroulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 00:00:21 by aroulin           #+#    #+#             */
/*   Updated: 2016/01/01 00:00:42 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char		*format(unsigned short nbr, long *grand)
{
	size_t	len;

	len = 1;
	*grand = 10;
	while (*grand <= nbr)
	{
		*grand *= 10;
		len++;
	}
	return (ft_strnew(len));
}

char			*ft_ustoa(unsigned short n)
{
	char			*nbr;
	long			grand;
	size_t			len;

	nbr = format(n, &grand);
	if (nbr == NULL)
		return (NULL);
	len = 0;
	while (grand > 1)
	{
		grand = grand / 10 == 0 ? 1 : grand / 10;
		nbr[len++] = '0' + (n / grand);
		n = n % grand;
	}
	return (nbr);
}
