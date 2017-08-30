/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <aroulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 00:00:21 by aroulin           #+#    #+#             */
/*   Updated: 2016/01/01 00:00:42 by aroulin          ###   ########.fr       */
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
