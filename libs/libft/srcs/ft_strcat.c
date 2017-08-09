/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 17:51:02 by jgraille          #+#    #+#             */
/*   Updated: 2016/11/30 14:09:16 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dst, const char *src)
{
	void	*ptr;
	size_t	len;

	ptr = (void *)(dst + ft_strlen(dst));
	len = ft_strlen(src);
	ft_memcpy(ptr, (void *)src, len);
	((char *)ptr)[len] = 0;
	return (dst);
}
