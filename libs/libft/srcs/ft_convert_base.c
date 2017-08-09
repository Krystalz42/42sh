/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 14:02:50 by jgraille          #+#    #+#             */
/*   Updated: 2017/01/07 15:46:53 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char			*convert_int_to_base(char *str, long long nb, char *base)
{
	long long		base_x;
	long long		number;
	long long		i;

	base_x = 0;
	while (base[base_x])
		base_x++;
	i = 0;
	while (nb > 0 || i == 0)
	{
		number = nb % base_x;
		str[i] = base[number];
		nb = nb / base_x;
		i++;
	}
	str[i] = '\0';
	return (str);
}

static long long	c_to_int(char c, char *base)
{
	long long		i;

	i = 0;
	while (base[i] != c && base[i] != '\0')
		i++;
	if (base[i] == '\0')
		return (0);
	return (i);
}

static long long	convert_base_to_int(char *nb, char *base)
{
	long long	base_x[2];
	long long	number;
	long long	i;

	base_x[0] = 0;
	number = 0;
	while (base[base_x[0]] != '\0')
		base_x[0]++;
	i = 0;
	while (nb[i] != '\0')
		i++;
	base_x[1] = 1;
	while (--i >= 0)
	{
		number += c_to_int(nb[i], base) * base_x[1];
		base_x[1] = base_x[1] * base_x[0];
	}
	return (number);
}

char				*ft_convert_base(char *n, char *bf, char *bt)
{
	long long	nb;
	char		*str;
	char		tmp;
	long long	i;
	long long	i2;

	str = ft_strnew(32);
	nb = convert_base_to_int(n, bf);
	convert_int_to_base(str, nb, bt);
	i = 0;
	while (str[i])
		i++;
	i2 = 0;
	while (i2 < --i)
	{
		tmp = str[i2];
		str[i2] = str[i];
		str[i] = tmp;
		i2++;
	}
	return (str);
}
