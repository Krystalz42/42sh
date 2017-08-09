/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 12:47:41 by jgraille          #+#    #+#             */
/*   Updated: 2017/03/06 20:34:08 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*freshstr;
	size_t	i;

	freshstr = (char *)malloc(len + 1);
	if (freshstr != NULL)
	{
		i = 0;
		while (i < len)
		{
			freshstr[i] = s[i + start];
			i++;
		}
		freshstr[i] = '\0';
	}
	return (freshstr);
}
