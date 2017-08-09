/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 14:14:28 by jgraille          #+#    #+#             */
/*   Updated: 2016/12/07 10:57:23 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int		ft_count(char const *s, const char *s2)
{
	int		count;
	size_t	i;
	size_t	len;
	size_t	len2;

	len = ft_strlen(s);
	len2 = ft_strlen(s2);
	count = 0;
	i = len2;
	while (i < len)
	{
		if (!ft_strncmp(s + i, s2, len2) && ft_strncmp(s + i - len2, s2, len2))
			count++;
		if (ft_strnequ(s + i, s2, len2))
			i = i + len2;
		else
			i++;
	}
	if (!ft_strnequ(s + len - len2, s2, len2))
		count++;
	return (count);
}

static void		writetable(char const *s, char **table, const char *s2)
{
	size_t len;
	size_t len2;
	size_t i;
	size_t start;

	len = ft_strlen(s);
	len2 = ft_strlen(s2);
	i = len2;
	start = ft_strnequ(s, s2, len2) ? len2 : 0;
	while (i < len)
	{
		if (!ft_strncmp(s + i, s2, len2) && ft_strncmp(s + i - len2, s2, len2))
		{
			*(table) = ft_strsub(s, start, i - start);
			table++;
		}
		if (i - len2 <= len && ft_strnequ(s + i, s2, len2))
		{
			start = i + len2;
			i = start - 1;
		}
		i++;
	}
	if (!ft_strnequ(s + len - len2, s2, len2))
		*(table++) = ft_strsub(s, start, len - start);
}

char			**ft_split(char	const *s, const char *str)
{
	char	**table;
	int		count;

	if (ft_strlen(str) > 1)
	{
		count = ft_count(s, str);
		if (*s != 0 && count > 0)
		{
			table = (char **)malloc(sizeof(char *) * (count + 1));
			if (table == NULL)
				return (NULL);
			writetable(s, table, str);
			table[count] = 0;
		}
		else
		{
			table = (char **)malloc(sizeof(char*));
			table[0] = (char *)malloc(1);
			table[0] = 0;
		}
		return (table);
	}
	else
		return (ft_strsplit(s, str[0]));
}
