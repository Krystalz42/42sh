/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <aroulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 00:00:21 by aroulin           #+#    #+#             */
/*   Updated: 2016/01/01 00:00:42 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

static char		*fill_point(char *str, size_t lp)
{
	size_t	len;
	char	*tmp;
	char	*str2;
	size_t	i;

	i = 0;
	if (lp > 0)
	{
		len = ft_strlen(str);
		tmp = ft_strnew(len + 1);
		str2 = str;
		while (i < len + 1)
		{
			tmp[i++] = *(str2++);
			if (len - i == lp)
				tmp[i++] = '.';
		}
		ft_memdel((void **)&str);
		return (tmp);
	}
	else
		return (str);
}

char			*ft_ftoa(double nb, size_t precision)
{
	char	*str;
	size_t	len;
	size_t	i;
	long	limit;

	limit = 10000000000000000;
	str = ft_lltoa((long long)nb);
	len = ft_strlen(str);
	i = 0;
	while (i <= precision)
	{
		str = (char *)ft_realloc((void **)&str, ++len + 1);
		while (nb >= limit || nb <= -limit)
			nb += nb >= limit ? -limit : limit;
		nb *= nb < 0 ? -10 : 10;
		str[len - 1] = ('0' + (((long)nb) % 10));
		i++;
	}
	str[len - 2] += str[len - 1] >= '5' ? 1 : 0;
	str[len - 1] = 0;
	str = fill_point(str, precision);
	return (str);
}
