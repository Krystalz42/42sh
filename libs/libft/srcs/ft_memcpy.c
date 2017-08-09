/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftmemcpy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 13:37:13 by jgraille          #+#    #+#             */
/*   Updated: 2017/01/08 20:15:29 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*dest;

	i = 0;
	if (src == NULL)
		return ((void *)dst);
	dest = (char *)dst;
	while (i < n)
	{
		dest[i] = ((char *)src)[i];
		i++;
	}
	return ((void *)dest);
}
