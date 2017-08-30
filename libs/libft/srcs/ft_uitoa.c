/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <aroulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 00:00:21 by aroulin           #+#    #+#             */
/*   Updated: 2016/01/01 00:00:42 by aroulin          ###   ########.fr       */
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
