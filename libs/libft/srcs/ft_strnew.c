/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 16:51:02 by jgraille          #+#    #+#             */
/*   Updated: 2016/11/21 14:38:09 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char *str;

	size++;
	str = (char *)malloc(size);
	if (str == NULL)
		return (NULL);
	while (size != 0)
	{
		str[size - 1] = 0;
		size--;
	}
	return (str);
}
