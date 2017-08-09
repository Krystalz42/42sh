/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 18:40:51 by aroulin           #+#    #+#             */
/*   Updated: 2017/04/18 17:24:34 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_printf.h>

char	fill_char(char *str, t_fmtid id)
{
	id.sign = 0;
	if (str[0] == '-')
		id.sign = '-';
	else if (id.flag && ft_strchr(id.flag, '+'))
		id.sign = '+';
	else if (id.flag && ft_strchr(id.flag, ' '))
		id.sign = ' ';
	return (id.sign);
}
