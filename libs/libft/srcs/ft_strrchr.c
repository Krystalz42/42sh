/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 13:09:36 by jgraille          #+#    #+#             */
/*   Updated: 2016/11/11 13:17:33 by jgraille         ###   ########.fr       */
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
