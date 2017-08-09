/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 13:19:33 by jgraille          #+#    #+#             */
/*   Updated: 2017/01/15 15:10:33 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	size_t	len;

	if (big)
	{
		len = ft_strlen(little);
		if (ft_strlen(big) < len)
			return (NULL);
		if (len == 0)
			return ((char *)big);
		while (*big)
		{
			if (!ft_strncmp(big, little, len))
				return ((char *)big);
			big++;
		}
	}
	return (NULL);
}
