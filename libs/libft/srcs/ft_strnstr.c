/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <aroulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 00:00:21 by aroulin           #+#    #+#             */
/*   Updated: 2016/01/01 00:00:42 by aroulin          ###   ########.fr       */
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
