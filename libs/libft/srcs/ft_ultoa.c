/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 21:12:27 by aroulin           #+#    #+#             */
/*   Updated: 2017/01/11 12:43:09 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>

char			*ft_ultoa(unsigned long n)
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
