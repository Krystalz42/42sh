/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 15:25:50 by jgraille          #+#    #+#             */
/*   Updated: 2017/01/11 12:42:23 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char			*ft_uitoa(unsigned int n)
{
	char			*nbr;
	size_t			len;

	len = 0;
	if (n == 0)
		return (ft_strdup("0"));
	nbr = ft_strnew(0);
	while (n > 0)
	{
		nbr = ft_realloc((void **)&nbr, len + 2);
		nbr[len] = (n % 10) + 48;
		n /= 10;
		len++;
	}
	nbr[len] = '\0';
	ft_strrev(nbr);
	return (nbr);
}
