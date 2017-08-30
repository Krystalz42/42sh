/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <aroulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 00:00:21 by aroulin           #+#    #+#             */
/*   Updated: 2016/01/01 00:00:42 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <libft.h>
#include <stdarg.h>
#include <stdlib.h>

char		*part_base(t_fmtid *id, va_list *ap)
{
	char *tmp;
	char *str;
	char *base;

	base = ft_strchr("oO", id->arg) ? BASE_OCT : BASE_HEX;
	base = ft_strchr("bB", id->arg) ? BASE_BIN : base;
	str = conv_base(*id, ap);
	if (*str == '0' && id->flag && ft_strchr(id->flag, '.') && id->lp == 0 &&
			!(ft_strchr(id->flag, '#') && ft_strchr("oO", id->arg)))
		str = NULL;
	if (str != NULL && *str == '0' && id->flag != NULL)
	{
		tmp = ft_str_charout(id->flag, "#");
		ft_memdel((void **)&id->flag);
		id->flag = tmp;
	}
	tmp = ft_convert_ubase(str, BASE_DEC, base);
	ft_memdel((void **)&str);
	if (id->flag != NULL && ft_strchr(id->flag, '-'))
		str = fill(fill_hash(fill_last(tmp, *id), *id), *id);
	else
		str = fill_hash(fill(fill_last(tmp, *id), *id), *id);
	if (ft_islower(id->arg))
		ft_str_tolower(str);
	return (str);
}
