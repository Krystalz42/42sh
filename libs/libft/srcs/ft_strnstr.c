/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 18:20:42 by jgraille          #+#    #+#             */
/*   Updated: 2016/11/30 15:22:18 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		lenlit;

	lenlit = ft_strlen(little);
	if (ft_strlen(big) < lenlit)
		return (NULL);
	if (lenlit == 0)
		return ((char *)big);
	while (*big && lenlit <= len)
	{
		if (!ft_strncmp(big, little, lenlit))
			return ((char *)big);
		big++;
		len--;
	}
	return (NULL);
}
