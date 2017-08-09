/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 15:10:06 by jgraille          #+#    #+#             */
/*   Updated: 2017/01/15 15:10:09 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <limits.h>

char			*ft_ulltoa(unsigned long long n)
{
	char				*nbr;
	size_t				len;

	len = 0;
	if (n == 0)
		return (ft_strdup("0"));
	nbr = ft_strnew(0);
	while (n > 0)
	{
		nbr = (char *)ft_realloc((void **)&nbr, len + 2);
		nbr[len] = n % 10 + 48;
		n /= 10;
		len++;
	}
	nbr[len] = '\0';
	ft_strrev(nbr);
	return (nbr);
}
