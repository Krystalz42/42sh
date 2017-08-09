/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_tolower.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 16:07:55 by jgraille          #+#    #+#             */
/*   Updated: 2017/01/08 20:19:23 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_str_tolower(char *s)
{
	char *tmp;

	if (s == NULL)
		return (NULL);
	tmp = s;
	while (*s)
	{
		*s = ft_tolower((int)*s);
		s++;
	}
	return (tmp);
}
