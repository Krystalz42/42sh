/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 10:08:59 by jgraille          #+#    #+#             */
/*   Updated: 2017/01/15 15:10:58 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *src)
{
	size_t	len;
	char	*copy;

	if (src == NULL)
		return (NULL);
	len = ft_strlen(src);
	copy = ft_strnew(len);
	ft_memcpy((void *)copy, (const void *)src, len);
	return (copy);
}
