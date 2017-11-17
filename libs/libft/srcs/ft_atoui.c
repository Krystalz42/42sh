/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoui.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <aroulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 19:10:10 by aroulin           #+#    #+#             */
/*   Updated: 2017/11/17 17:22:17 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int			check_pass(char c)
{
	if (c == 32 || c == 11 || c == 9 || c == '\r' || c == '\n' || c == '\f')
		return (1);
	return (0);
}

unsigned int		ft_atoui(const char *str)
{
	unsigned int	number;

	if (!str)
		return (0);
	while (check_pass((unsigned char)(*str)))
		str++;
	number = 0;
	while (*str && ft_isdigit(*str))
	{
		number = number * 10 + (unsigned char)(*str) - '0';
		str++;
	}
	return (number);
}
