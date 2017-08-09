/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_nu.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 14:28:16 by aroulin           #+#    #+#             */
/*   Updated: 2017/04/18 17:28:13 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <ft_printf.h>
#include <libft.h>

char		*part_nu(t_fmtid id, va_list *ap)
{
	char *str;
	char *tmp;

	tmp = converted(id, ap);
	if (*tmp == '0' && ft_strlen(tmp) == 1 &&
			id.flag && ft_strchr(id.flag, '.'))
		*tmp = 0;
	id.sign = fill_char(tmp, id);
	str = ft_str_charout(tmp, "-");
	ft_memdel((void **)&tmp);
	str = fill_last(str, id);
	if (id.flag != NULL && ft_strchr(id.flag, '-'))
	{
		str = fill_sign(str, id);
		str = fill(str, id);
	}
	else
	{
		str = fill(str, id);
		str = fill_sign(str, id);
	}
	return (str);
}
