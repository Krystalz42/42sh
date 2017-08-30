/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <aroulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 00:00:21 by aroulin           #+#    #+#             */
/*   Updated: 2016/01/01 00:00:42 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strncat(char *dst, const char *src, size_t n)
{
	size_t	len;
	void	*ptr;

	ptr = (void *)(dst + ft_strlen(dst));
	len = ft_strlen(src);
	len = len < n ? len : n;
	if (len > 0 && n > 0)
		ft_memcpy(ptr, (const void *)src, len);
	((char *)ptr)[len] = 0;
	return (dst);
}
