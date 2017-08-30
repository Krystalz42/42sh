/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <aroulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 00:00:21 by aroulin           #+#    #+#             */
/*   Updated: 2016/01/01 00:00:42 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	int i;
	int	lastfind;

	i = 0;
	lastfind = -1;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			lastfind = i;
		i++;
	}
	lastfind = c == 0 ? i : lastfind;
	if (lastfind == -1)
		return (NULL);
	else
		return ((char *)s + lastfind);
}
