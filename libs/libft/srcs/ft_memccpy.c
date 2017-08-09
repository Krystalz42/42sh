/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 14:43:13 by jgraille          #+#    #+#             */
/*   Updated: 2016/11/30 13:22:02 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char	*cpy_src;
	char	*cpy_dst;
	size_t	i;

	cpy_src = (char *)src;
	cpy_dst = (char *)dst;
	i = 0;
	while (i < n)
	{
		cpy_dst[i] = cpy_src[i];
		if (cpy_src[i] == c)
			return ((void *)(cpy_dst + i + 1));
		i++;
	}
	return (NULL);
}
