/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <aroulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 00:00:21 by aroulin           #+#    #+#             */
/*   Updated: 2016/01/01 00:00:42 by aroulin          ###   ########.fr       */
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
