/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <aroulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 00:00:21 by aroulin           #+#    #+#             */
/*   Updated: 2016/01/01 00:00:42 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	lens1;
	size_t	lens2;
	char	*freshstr;
	size_t	i;

	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	freshstr = (char *)malloc(lens1 + lens2 + 1);
	i = 0;
	if (freshstr != NULL)
	{
		while (i < lens1)
		{
			freshstr[i] = s1[i];
			i++;
		}
		i = 0;
		while (i < lens2)
		{
			freshstr[lens1 + i] = s2[i];
			i++;
		}
		freshstr[lens1 + i] = '\0';
	}
	return (freshstr);
}
