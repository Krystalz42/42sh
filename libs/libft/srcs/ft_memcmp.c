/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 16:39:33 by jgraille          #+#    #+#             */
/*   Updated: 2016/11/30 13:33:21 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	char	*cpy_s1;
	char	*cpy_s2;

	i = 0;
	cpy_s1 = (char *)s1;
	cpy_s2 = (char *)s2;
	while (i < n && cpy_s1[i] == cpy_s2[i])
		i++;
	if (i < n)
		return ((unsigned char)cpy_s1[i] - (unsigned char)cpy_s2[i]);
	return (0);
}
