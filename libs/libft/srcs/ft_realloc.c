/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 10:04:24 by jgraille          #+#    #+#             */
/*   Updated: 2017/04/20 15:54:28 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_realloc(void **ptr, size_t buff)
{
	void	*freshptr;

	if (!(freshptr = (void *)ft_memalloc(buff)))
		return (NULL);
	if (*ptr)
	{
		ft_memcpy(freshptr, *ptr, buff);
		ft_memdel(ptr);
	}
	return (freshptr);
}
