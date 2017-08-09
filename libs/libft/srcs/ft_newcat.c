/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 10:28:40 by jgraille          #+#    #+#             */
/*   Updated: 2016/12/03 11:01:37 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_newcat(char *str1, char *str2)
{
	char	*str;
	size_t	len;
	size_t	len2;

	len = ft_strlen(str1);
	len2 = ft_strlen(str2);
	if (!(str = (char *)ft_memalloc(len + len2 + 1)))
		return (NULL);
	ft_memcpy(str, str1, len);
	ft_memcpy(str + len, str2, len2);
	str[len + len2] = 0;
	return (str);
}
