/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_ubase.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 15:40:53 by jgraille          #+#    #+#             */
/*   Updated: 2017/01/08 20:09:12 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include <string.h>

static char					*convert_nu(unsigned long long nb, char *base)
{
	char			*str;
	char			*tmp;
	long long		base_x;
	long long		number;
	long long		i;

	tmp = ft_strnew(500);
	base_x = 0;
	while (base[base_x])
		base_x++;
	i = 0;
	while (nb > 0 || i == 0)
	{
		number = nb % base_x;
		tmp[i] = base[number];
		nb = nb / base_x;
		i++;
	}
	tmp[i] = '\0';
	str = ft_strdup(tmp);
	ft_memdel((void **)&tmp);
	return (str);
}

static short				c_to_int(char c, char *base)
{
	short	i;

	i = 0;
	if (c == '-')
		return (1);
	while (base[i] != c && base[i] != '\0')
		i++;
	if (base[i] == '\0')
		return (0);
	return (i);
}

static unsigned long long	convert_base_to_nu(char *nb, char *base)
{
	long long			base_x[2];
	unsigned long long	number;
	long long			i;

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
	number = nb[0] == '-' ? number * -1 : number;
	return (number);
}

char						*ft_convert_ubase(char *n, char *bf, char *bt)
{
	char				*str;
	char				tmp;
	long long			i;
	long long			i2;

	if (n == NULL)
		return (NULL);
	str = convert_nu(convert_base_to_nu(n, bf), bt);
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
