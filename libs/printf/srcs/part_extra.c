/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part_extra.c                                       :+:      :+:    :+:   */
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
#include <stdint.h>

char	*pointerarg(t_fmtid id, va_list *ap)
{
	char *str;
	char *tmp;

	tmp = ft_ultoa((unsigned long)va_arg(*ap, void*));
	str = ft_convert_base(tmp, BASE_DEC, BASE_HEX);
	ft_memdel((void *)&tmp);
	if (str[0] == '0' && ft_strchr(id.flag, '.') && id.lp == 0)
		str[0] = 0;
	if (id.flag)
		ft_str_charout(id.flag, "0");
	if (id.flag != NULL && ft_strchr(id.flag, '-'))
		str = fill(fill_pointer(fill_last(str, id), id), id);
	else
		str = fill_pointer(fill(fill_last(str, id), id), id);
	if (id.arg == 'p')
		str = ft_str_tolower(str);
	return (str);
}

char	*part_char(t_fmtid *id, va_list *ap)
{
	char *str;

	str = ft_strnew(1);
	str[0] = id->arg == '/' ? id->sign : (unsigned char)va_arg(*ap, int);
	if (str[0] == 0)
	{
		str = fill_tank(str, *id);
		if (id->flag && ft_strchr(id->flag, '-'))
			ft_putchar('\0');
		ft_putstr(str);
		if (!id->flag || !ft_strchr(id->flag, '-'))
			ft_putchar('\0');
		id->dif = ft_strdup("N");
	}
	else
		str = fill_str(str, *id);
	return (str);
}

char	*part_extra(t_fmtid *id, va_list *ap)
{
	char *str;

	str = NULL;
	if (ft_strchr("cC/", id->arg))
		return (part_char(id, ap));
	if (ft_strchr("%", id->arg))
	{
		str = ft_strnew(1);
		str[0] = '%';
		str = fill_str(str, *id);
		return (str);
	}
	if (ft_strchr("pP", id->arg))
		str = pointerarg(*id, ap);
	str = fill(str, *id);
	return (str);
}
