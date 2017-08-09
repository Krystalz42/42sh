/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_toupper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 15:37:19 by jgraille          #+#    #+#             */
/*   Updated: 2017/01/08 20:19:56 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_str_toupper(char *s)
{
	char *tmp;

	if (s == NULL)
		return (NULL);
	tmp = s;
	while (*s)
	{
		*s = ft_toupper((int)*s);
		s++;
	}
	return (tmp);
}
