/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 13:50:24 by jgraille          #+#    #+#             */
/*   Updated: 2016/11/18 10:57:55 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strtrim(char const *s)
{
	int		start;
	int		end;
	int		i;
	char	*freshstr;

	start = -1;
	end = 0;
	i = -1;
	while (s[++i])
		if (s[i] != ' ' && s[i] != '\t' && s[i] != '\n')
		{
			start = start == -1 ? i : start;
			end = i;
		}
	freshstr = (char *)malloc(end - start + 2);
	if (freshstr != NULL)
	{
		i = start - 1;
		while (++i <= end)
			freshstr[i - start] = s[i];
		freshstr[i - start] = '\0';
	}
	return (freshstr);
}
