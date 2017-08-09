/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 15:42:51 by jgraille          #+#    #+#             */
/*   Updated: 2016/11/11 16:39:07 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memalloc(size_t len)
{
	char	*mem;

	mem = malloc(len);
	if (mem == NULL)
		return (NULL);
	while (len-- != 0)
		*(mem + len) = 0;
	return ((void *)mem);
}
