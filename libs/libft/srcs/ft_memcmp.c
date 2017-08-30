/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <aroulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 00:00:21 by aroulin           #+#    #+#             */
/*   Updated: 2016/01/01 00:00:42 by aroulin          ###   ########.fr       */
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
