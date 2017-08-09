/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ustoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 20:20:35 by jgraille          #+#    #+#             */
/*   Updated: 2017/01/04 20:20:59 by jgraille         ###   ########.fr       */
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
