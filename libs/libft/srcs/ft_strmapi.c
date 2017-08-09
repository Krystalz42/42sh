/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 18:02:48 by jgraille          #+#    #+#             */
/*   Updated: 2016/11/18 10:36:18 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*newstr;
	size_t			len;
	unsigned int	i;

	len = ft_strlen(s);
	newstr = ft_strnew(len);
	if (newstr)
	{
		i = 0;
		while ((size_t)i < len)
		{
			newstr[i] = f(i, s[i]);
			i++;
		}
	}
	return (newstr);
}
