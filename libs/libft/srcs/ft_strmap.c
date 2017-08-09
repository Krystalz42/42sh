/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 17:37:43 by jgraille          #+#    #+#             */
/*   Updated: 2016/11/18 10:45:15 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*newstr;
	size_t	len;

	len = ft_strlen(s);
	newstr = ft_strnew(len);
	if (newstr)
	{
		while (len > 0)
		{
			newstr[len - 1] = f(s[len - 1]);
			len--;
		}
	}
	return (newstr);
}
