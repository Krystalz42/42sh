/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 12:27:13 by jgraille          #+#    #+#             */
/*   Updated: 2016/11/18 12:28:29 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		tochar(int i)
{
	return ('0' + i % 10);
}

void			ft_putnbr_fd(int n, int fd)
{
	long n2;
	long grand;

	n2 = n;
	if (n2 < 0)
	{
		ft_putchar_fd('-', fd);
		n2 = -n2;
	}
	grand = 10;
	while (grand < n2)
		grand *= 10;
	grand = grand / 10;
	while (grand >= 1)
	{
		ft_putchar_fd(tochar(n2 / grand), fd);
		n2 = n2 % grand;
		grand = grand / 10;
	}
}
