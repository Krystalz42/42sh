/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <aroulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 00:00:21 by aroulin           #+#    #+#             */
/*   Updated: 2016/01/01 00:00:42 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int		ft_count(char const *s, char c)
{
	int	count;
	int i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c && (i != 0 && s[i - 1] != c))
			count++;
		i++;
	}
	if (s[i] == 0 && s[i - 1] != c)
		count++;
	return (count);
}

static void		writetable(char const *s, char **table, char c)
{
	int countwords;
	int len;
	int i;

	len = 0;
	i = 0;
	countwords = 0;
	while (s[i])
	{
		if (s[i] != c)
			len++;
		if (s[i] == c && (i != 0 && s[i - 1] != c))
		{
			table[countwords++] = ft_strsub(s + i - len, 0, len);
			len = 0;
		}
		i++;
	}
	if (s[i] == 0 && s[i - 1] != c)
		table[countwords++] = ft_strsub(s + i - len, 0, len);
	table[countwords] = 0;
}

char			**ft_strsplit(char	const *s, char c)
{
	char	**table;

	if (*s != 0)
	{
		table = (char **)malloc(sizeof(char *) * (ft_count(s, c) + 1));
		if (table == NULL)
			return (NULL);
		writetable(s, table, c);
	}
	else
	{
		table = (char **)malloc(sizeof(char*));
		table[0] = (char *)malloc(1);
		table[0] = 0;
	}
	return (table);
}
