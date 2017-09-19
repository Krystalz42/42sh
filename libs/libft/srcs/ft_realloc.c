/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <aroulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 00:00:21 by aroulin           #+#    #+#             */
/*   Updated: 2016/01/01 00:00:42 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_realloc(void **ptr, size_t oldsize, size_t newsize)
{
	void	*freshptr;

	if (!(freshptr = (void *)ft_memalloc(newsize)))
		return (NULL);
	if (*ptr)
	{
		ft_memcpy(freshptr, *ptr, oldsize);
		ft_memdel(ptr);
	}
	return (freshptr);
}